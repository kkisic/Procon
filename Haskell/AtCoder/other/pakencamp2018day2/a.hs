main = do
  n <- readLn
  if n < 123
    then print n
    else print $ n - 1
