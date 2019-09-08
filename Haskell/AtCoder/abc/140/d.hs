import Data.List
main = do
  [n,k] <- map read . words <$> getLine :: IO [Int]
  s <- length . group <$> getLine
  print $ n - max 1 (s - k * 2)
