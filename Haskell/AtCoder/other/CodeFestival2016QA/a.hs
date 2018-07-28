main = do
  s <- getLine
  putStrLn $ (take 4 s) ++ " " ++ (drop 4 s)
