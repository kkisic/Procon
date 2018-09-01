main = do
  n <- readLn
  print $ (div n 2) * (div (n+1) 2)
