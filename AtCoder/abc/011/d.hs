import Data.Array.IO
import Data.List
import Control.Monad
import Text.Printf

type Arr = IOUArray (Int, Int) Double

main = do
  [n,d] <- map read . words <$> getLine :: IO [Int]
  [x,y] <- map (abs . read) . words <$> getLine :: IO [Int]
  solve n d x y

solve :: Int -> Int -> Int -> Int -> IO ()
solve n d x y = do
  if mod x d /= 0 || mod y d /= 0
    then print 0
    else do
      let x' = div x d
          y' = div y d
      if mod n 2 /= mod (x'+y') 2 || x'+y' > n
        then print 0
        else do
          table <- newArray ((0, -1), (n, n)) 0 :: IO Arr
          writeArray table (0, 0) 1.0
          foldM makeTable table [1..n]
          ans <- probability table n x' y'
          putStrLn $ printf "%.10f" ans

probability :: Arr -> Int -> Int -> Int -> IO Double
probability arr n x y = do
  let pattern = [(i, n-i) | i <- [x, x+2..n-y]]
  return =<< sum <$> mapM (prob arr x y) pattern

prob :: Arr -> Int -> Int -> (Int, Int) -> IO Double
prob arr x y (i, j) = do
  a <- readArray arr (i, div (i-x) 2)
  b <- readArray arr (j, div (j-y) 2)
  c <- readArray arr (i+j, i)
  return $ a * b * c

makeTable :: Arr -> Int -> IO Arr
makeTable arr i = foldM (makeTable' i) arr [0..i]

makeTable' :: Int -> Arr -> Int -> IO Arr
makeTable' i arr j = do
  x <- readArray arr (i-1, j-1)
  y <- readArray arr (i-1, j)
  writeArray arr (i, j) $ (x + y) / 2
  return arr
