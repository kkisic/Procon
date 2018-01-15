import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

inf = 10^9

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  edge <- map (\[x,y,z] -> (x,y,z)) <$> getInt2DListBC
  let edge1 = filter (\(x,_,_) -> x == 1) edge
      ne1 = M.fromList $ map (\(_,y,z) -> (y,z)) edge1
      neList = fst . unzip . M.toList $ ne1
      edge' = filter (\(x,_,_) -> x /= 1) edge
      index = [(k, i, j) | k <- [2..n], i <- [2..n], j <- [i..n]]
  cost <- newArray ((2, 2), (n, n)) inf :: IO Memo2D
  foldM initWF cost [(i,i,0) | i <- [2..n]]
  foldM initWF cost edge'
  foldM warshallFloyd cost index
  ans <- mapM (solve cost ne1) $ init . tails $ neList
  let ans' = filter (<inf) ans
  if ans' == []
    then print $ negate 1
    else print $ minimum ans'

solve :: Memo2D -> M.IntMap Int -> [Int] -> IO Int
solve memo ne n@(x:xs) = do
  let toX = fromJust $ M.lookup x ne
  cost <- mapM readWeight xs
  if cost == []
    then return inf
    else return $ toX + (minimum cost)
    where readWeight :: Int -> IO Int
          readWeight i = do
            let toI = fromJust $ M.lookup i ne
            c <- readArray memo (x, i)
            return $ toI + c

--重み付き辺
type EdgeW = (Int, Int, Int)
type Memo2D = IOUArray (Int, Int) Int

initWF :: Memo2D -> EdgeW -> IO Memo2D
initWF memo (x, y, d) = do
  writeArray memo (x, y) d
  writeArray memo (y, x) d
  return memo

warshallFloyd :: Memo2D -> (Int, Int, Int) -> IO Memo2D
warshallFloyd memo (k, i, j) = do
  x <- readArray memo (i, j)
  y <- readArray memo (i, k)
  z <- readArray memo (k, j)
  let minWeight = min x $ y + z
  writeArray memo (i, j) minWeight
  writeArray memo (j, i) minWeight
  return memo

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

