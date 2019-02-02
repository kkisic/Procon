import Data.List
main = do
  a <- sum . map read . words <$> getLine :: IO Int
  b <- sum . map read . words <$> getLine :: IO Int
  print $ max a b
