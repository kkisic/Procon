import qualified Data.ByteString.Char8 as BC
import Data.Array.IO
import Data.Maybe (fromJust)
import Data.List
import Control.Monad

type EdgeW = (Int, Int, Int)
type Memo2D = IOUArray (Int, Int) Int

inf = 10^7

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  edge <- map (\[x,y,z] -> (x,y,z)) <$> getInt2DListBC
  memo <- newArray ((1, 1), (n, n)) inf :: IO Memo2D
  let index = [(k, i, j) | k <- [1..n], i <- [1..n], j <- [i..n]]
  foldM initWF memo [(i, i, 0) | i <- [1..n]]
  foldM initWF memo edge
  foldM warshallFloyd memo index
  ans <- minimum <$> mapM (solve memo n) [1..n]
  print ans

solve :: Memo2D -> Int -> Int -> IO Int
solve memo n i = do
  ans <- maximum . filter (/= inf) <$> mapM (\x -> readArray memo (i, x)) [1..n]
  return ans

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

