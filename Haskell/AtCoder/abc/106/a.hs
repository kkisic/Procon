main = do
  [a, b] <- map read . words <$> getLine
  print $ (a-1) * (b-1)
