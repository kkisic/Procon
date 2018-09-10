main = do
  [n, x] <- map read . words <$> getLine
  s <- map (abs . subtract x . read) . words <$> getLine
  print $ foldl1 gcd s
