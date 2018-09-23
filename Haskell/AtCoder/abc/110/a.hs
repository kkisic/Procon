import Data.List
main = do
  a <- sort . map read . words <$> getLine
  print $ (maximum a) * 10 + (a !! 0) + (a !! 1)
