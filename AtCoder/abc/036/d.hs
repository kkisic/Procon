import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Array.IO

type Memo = IOUArray (Int, Int) Int
type Edge = (Int, Int)
type Graph = M.IntMap [Int]

modN = 10^9+7

main = do
  n <- readLn :: IO Int
  edge <- map (\[x,y] -> (x,y)) <$> getInt2DListBC
  memo <- newArray ((1, 1), (2, n)) (-1) :: IO Memo
  let graph = foldl makeGraph M.empty edge
  print =<< dp graph memo

--(1, _):white, (2, _):all
dp :: Graph -> Memo -> IO Int
dp graph memo = all 0 1
  where white :: Int -> Int -> IO Int
        white parent i = do
          x <- readArray memo (1, i)
          if x == (-1)
            then do
              let ne = fromJust $ M.lookup i graph
              if length ne == 1 && i /= 1
                then do
                  writeArray memo (1, i) 1
                  return 1
                else do
                  c <- foldl1 (\x y -> flip mod modN $ x * y) <$> mapM (all i) (filter (/=parent) ne)
                  writeArray memo (1, i) c
                  return c
            else return x
        all :: Int -> Int -> IO Int
        all parent i = do
          x <- readArray memo (2, i)
          if x == (-1)
            then do
              let ne = fromJust $ M.lookup i graph
              if length ne == 1 && i /= 1
                then do
                  writeArray memo (2, i) 2
                  return 2
                else do
                  w <- foldl1 (\x y -> flip mod modN $ x * y) <$> mapM (white i) (filter (/=parent) ne)
                  wi <- white parent i
                  writeArray memo (2, i) $ flip mod modN $ w + wi
                  return $ flip mod modN $ w + wi
            else return x

--重み無し隣接リスト
makeGraph :: Graph -> Edge -> Graph
makeGraph graph (x, y) =
  let nX = M.lookup x graph
      nY = M.lookup y graph
      vX = if nX == Nothing
             then M.insert x [y] graph
             else M.insert x (y : (fromJust nX)) graph
  in if nY == Nothing
       then M.insert y [x] vX
       else M.insert y (x : (fromJust nY)) vX

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
