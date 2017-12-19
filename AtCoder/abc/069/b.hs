main = do
  (s:ss) <- getLine
  putStrLn $ (s:(show . length . init $ ss)) ++ [last ss]

