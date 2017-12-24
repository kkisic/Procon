import Control.Monad
import Data.Array.IO

type Image = IOUArray (Int, Int) Char

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  a <- concat <$> replicateM n getLine
  b <- concat <$> replicateM m getLine
  imageA <- newListArray ((1, 1), (n, n)) a :: IO Image
  imageB <- newListArray ((1, 1), (m, m)) b :: IO Image
  let index = [(i, j) | i <- [1..(n-m+1)], j <- [1..(n-m+1)]]
  ans <- mapM (match m imageA imageB) index
  if or ans then putStrLn "Yes"
            else putStrLn "No"

match :: Int -> Image -> Image -> (Int, Int) -> IO Bool
match m a b (i, j) = do
  let index = [(s, t) | s <- [i..(i+m-1)], t <- [j..(j+m-1)]]
  ans <- mapM (match' a b) $ zip index [(x, y) | x <- [1..m], y <- [1..m]]
  return $ and ans

match' :: Image -> Image -> ((Int, Int), (Int, Int)) -> IO Bool
match' a b (i, j) = do
  x <- readArray a i
  y <- readArray b j
  return $ x == y
