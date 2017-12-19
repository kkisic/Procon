main = do
  getLine
  input <- map read . lines <$> getContents :: IO [Int]
  print $ foldl1 lcm input