main = do
  [n, m] <- map read . words <$> getLine
  print $ (-) m $ gcd n m
