import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  edge <- (\[x,y,z] -> zip3 x y z) . transpose <$> getInt2DListBC
  graph <- newArray ((0, 1), (n, n)) (10^9) :: IO Memo2D
  foldM initWF graph edge
  foldM initWF graph [(i, i, 0) | i <- [1..n]]
  let index = [(k, i, j) | k <- [1..n], i <- [1..n], j <- [1..n]]
  foldM warshallFloyd graph index
  writeArray graph (0, 1) 0
  foldM (count n) graph edge
  ans <- readArray graph (0, 1)
  print ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

type Memo2D = IOUArray (Int, Int) Int
type Road = IOUArray (Int, Int) Bool

initWF :: Memo2D -> (Int, Int, Int) -> IO Memo2D
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
  return memo

count :: Int -> Memo2D -> (Int, Int, Int) -> IO Memo2D
count n memo e = do
  c <- readArray memo (0, 1)
  b <- foldM (warshallFloyd' e memo) False [1..n]
  let c' = if b then c else c + 1
  writeArray memo (0, 1) c'
  return memo

--graph(0,1) : count
warshallFloyd' :: (Int, Int, Int) -> Memo2D -> Bool -> Int -> IO Bool
warshallFloyd' (i, j, w) memo b s = do
  x <- readArray memo (s, i)
  y <- readArray memo (s, j)
  return $ b || x + w == y
