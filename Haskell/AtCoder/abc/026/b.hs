import Data.List
import Text.Printf

main = do
  n <- readLn :: IO Int
  r <- sortBy (\x y -> compare y x) . map read . lines <$> getContents :: IO [Int]
  let s = realToFrac $ solve 0 r :: Double
  putStrLn $ printf "%.9f" $ s * 3.1415926535

solve :: Int -> [Int] -> Int
solve _ []     = 0
solve 0 (x:xs) = (solve 1 xs) + x^2
solve 1 (x:xs) = (solve 0 xs) - x^2
