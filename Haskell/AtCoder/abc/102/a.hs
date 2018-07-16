main = do
  x <- readLn
  if mod x 2 == 0
    then print x
    else print $ x * 2
