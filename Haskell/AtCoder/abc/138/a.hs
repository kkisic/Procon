main = do
  a <- readLn
  s <- getLine
  if a < 3200
    then putStrLn "red"
    else putStrLn s
