import Data.Array.IO
import Data.Vector.Unboxed (Vector, (!), fromList)
import Control.Monad

type Memo = IOUArray (Int, Int) Int

main = do
  [n, a] <- map read . words <$> getLine :: IO [Int]
  x <- map read . words <$> getLine :: IO [Int]
  memo <- newArray ((0, negate (n * 50)), (n, n*50)) 0 :: IO Memo
  writeArray memo (0, 0) 1
  let y = map (flip (-) a) x
      y' = fromList (0:y) :: Vector Int
      max = maximum x
      idx = [(i, j) | i <- [1..n], j <- [negate (n * 50)..n * 50]]
  foldM (dp y' n max) memo idx
  ans <- readArray memo (n, 0)
  print $ ans - 1

dp :: Vector Int -> Int -> Int -> Memo -> (Int, Int) -> IO Memo
dp y n x memo (i, j)
  | i >= 1 && (j - (y ! i) < (negate $ n*x) || j - (y ! i) > n*x) = do
    a <- readArray memo (i-1, j)
    writeArray memo (i, j) a
    return memo
  | i >= 1 && (negate $ n*x) <= j - (y ! i) && j - (y ! i) <= n*x = do
    a <- readArray memo (i-1, j)
    b <- readArray memo (i-1, j-(y!i))
    writeArray memo (i, j) $ a + b
    return memo
  | otherwise = return memo
