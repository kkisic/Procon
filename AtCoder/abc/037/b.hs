import Data.Array.IO
import Control.Monad

type Array = IOUArray Int Int

main = do
  [n,q] <- map read . words <$> getLine :: IO [Int]
  input <- map (map read . words) . lines <$> getContents :: IO [[Int]]
  a <- newArray (1, n) 0 :: IO Array
  solve a input
  ans <- getElems a
  putStr $ unlines . map show $ ans

solve :: Array -> [[Int]] -> IO Array
solve a [] = return a
solve a ([l,r,t]:qs) = do
  foldM (write t) a [l..r]
  solve a qs

write :: Int -> Array -> Int -> IO Array
write t a i = do
  writeArray a i t
  return a
