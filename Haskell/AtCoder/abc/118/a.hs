main = do
  [a,b] <- map read . words <$> getLine
  if mod b a == 0
    then print $ a + b
    else print $ b - a
