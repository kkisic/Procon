import Data.List
main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  l <- reverse . sort . map read . words <$> getLine :: IO [Int]
  print $ sum . take k $ l
