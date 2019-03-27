main = do
  [a,b,c] <- map read . words <$> getLine
  print $ min c $ div b a
