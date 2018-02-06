main = do
  s <- getLine
  putStrLn $ (take 3 s) ++ "8" ++ (drop 4 s)

