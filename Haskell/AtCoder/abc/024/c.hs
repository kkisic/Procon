import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

type People = (Int, Int)
type Movable = (Int, Int, Int)
type Arr = IOUArray Int Int

main = do
  [n,d,k] <- map read . words <$> getLine :: IO [Int]
  m <- replicateM d getIntListBC
  p <- replicateM k getIntListBC
  date <- newArray (1, k) 0 :: IO Arr
  pos <- newListArray (1, k) (head . transpose $ p) :: IO Arr
  let people = zipWith (\[x,y] z -> (z,y)) p [1..k]
      movable = zipWith (\[x,y] z -> (x,y,z)) m [1..d]
  foldM (move people pos) date movable
  ans <- getElems date
  putStr $ unlines . map show $ ans

move :: [People] -> Arr -> Arr -> Movable -> IO Arr
move people pos date m = foldM (move' pos m) date people

move' :: Arr -> Movable -> Arr -> People -> IO Arr
move' pos (l,r,now) date (n, dst) = do
  src <- readArray pos n
  move'' src
  return date
    where move'' :: Int -> IO ()
          move'' src
            | src < dst && l <= src && src <= r && r < dst = do
              writeArray pos n r
              return ()
            | src < dst && l <= src && src <= r && r >= dst = do
              writeArray pos n dst
              writeArray date n now
              return ()
            | src > dst && l <= src && src <= r && dst < l = do
              writeArray pos n l
              return ()
            | src > dst && l <= src && src <= r && dst >= l = do
              writeArray pos n dst
              writeArray date n now
              return ()
            | otherwise = return ()

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
