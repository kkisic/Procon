main = do
  [h,w] <- map read . words <$> getLine
  [a,b] <- map read . words <$> getLine
  print $ h * w - h * b - a * w + a * b
