main = do
  [n, i] <- map read . words <$> getLine
  print $ n - i + 1
