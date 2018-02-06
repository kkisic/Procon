import Data.Array.IO
import Control.Monad

main = do
  [n, m] <- map read . words <$> getLine :: IO [Int]
  input <- map (map read . words) . lines <$> getContents :: IO [[Int]]
  memo <- newArray (1, n) 0 :: IO (IOUArray Int Int)
  foldM memoize memo input
  ans <- getElems memo
  putStr $ unlines . map show $ ans

memoize :: IOUArray Int Int -> [Int] -> IO (IOUArray Int Int)
memoize memo [i, j] = do
  ii <- readArray memo i
  jj <- readArray memo j
  writeArray memo i (ii+1)
  writeArray memo j (jj+1)
  return memo
