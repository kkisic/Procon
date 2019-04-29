main = do
  getLine 
  s <- getLine
  n <- readLn
  putStrLn $ map (\x -> if x == (s !! (n - 1)) then x else '*') s
