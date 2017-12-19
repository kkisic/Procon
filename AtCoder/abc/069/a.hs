main = do
  [x, y] <- map read . words <$> getLine :: IO [Int]
  print $ (x - 1) * (y - 1)
