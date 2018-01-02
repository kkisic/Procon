import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Data.Bits
import Control.Monad

type Memo = IOUArray Int Int
type Edge = (Int, Int)
type Graph = M.IntMap [Int]

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  edge <- map (\[x,y] -> (x-1, y-1)) <$> getInt2DListBC
  memo <- newArray (0, 2^n-1) 0 :: IO Memo
  writeArray memo 0 1
  let pattern = permutations [1..n]
      idx = [(a, v) | a <- [0..2^n-1], v <- [0..n-1]]
      graph = foldl makeGraph M.empty edge
  foldM (dp graph) memo idx
  ans <- readArray memo $ 2^n-1
  print ans

dp :: Graph -> Memo -> (Int, Int) -> IO Memo
dp graph memo (a, v) = do
  if 1 .&. shiftR a v == 1
    then return memo
    else do
      let sK = M.lookup v graph
          isRight = if sK == Nothing
                    then True
                    else not . contains a $ fromJust sK
      if isRight
        then do
          x <- readArray memo a
          y <- readArray memo $ a .|. shiftL 1 v
          writeArray memo (a .|. shiftL 1 v) $ x + y
          return memo
        else return memo


contains :: Int -> [Int] -> Bool
contains a sk = or $ map ((==1) . (.&.1) . shiftR a) sk

makeGraph :: Graph -> Edge -> Graph
makeGraph graph (x, y) =
  let nX = M.lookup x graph
  in if nX == Nothing
       then M.insert x [y] graph
       else M.insert x (y : (fromJust nX)) graph

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
