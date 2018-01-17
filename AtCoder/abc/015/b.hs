main = do
  getLine
  a <- filter (/=0) . map read . words <$> getLine :: IO [Double]
  print $ ceiling $ (sum a) / (realToFrac $ length a)
