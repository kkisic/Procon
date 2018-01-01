main = do
  s <- getLine
  i <- readLn :: IO Int
  putStrLn $ [s !! (i-1)]
