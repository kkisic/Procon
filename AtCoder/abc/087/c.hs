import Data.List

main = do
  n <- readLn :: IO Int
  a <- map read . words <$> getLine :: IO [Int]
  b <- reverse . map read . words <$> getLine :: IO [Int]
  let ans = maximum $ map (solve a b n) [1..n]
  print ans

solve :: [Int] -> [Int] -> Int -> Int -> Int
solve a b n i =
  let aS = sum $ take i a
      bS = sum $ take (n-i+1) b
  in aS + bS
