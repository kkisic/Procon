import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Memo = IOUArray (Int, Int) Int

main = do
  [n, m, r] <- map read . words <$> getLine :: IO [Int]
  rr <- map read . words <$> getLine :: IO [Int]
  input <- (\[x, y, z] -> zip3 x y z) . transpose <$> getInt2DListBC
  edge <- newArray ((1, 1), (n, n)) (10^9) :: IO Memo
  foldM memoize edge input
  foldM memoize edge [(i, i, 0) | i <- [1..n]]
  let index = [(k, i, j) | k <- [1..n], i <- [1..n], j <- [1..n]]
  foldM warshallFloyd edge index
  print $ permutations rr
  ans <- mapM (readMemo edge) $ permutations rr
  putStrLn . show . minimum $ ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

memoize :: Memo -> (Int, Int, Int) -> IO Memo
memoize memo (x, y, d) = do
  writeArray memo (x, y) d
  writeArray memo (y, x) d
  return memo

warshallFloyd :: Memo -> (Int, Int, Int) -> IO Memo
warshallFloyd memo (k, i, j) = do
  x <- readArray memo (i, j)
  y <- readArray memo (i, k)
  z <- readArray memo (k, j)
  let minWeight = min x $ y + z
  writeArray memo (i, j) minWeight
  return memo

readMemo :: Memo -> [Int] -> IO Int
readMemo memo (_:[]) = return 0
readMemo memo (s:t:ts) = do
  d <- readArray memo (s, t)
  sum <- (+d) <$> readMemo memo (t:ts)
  return sum
