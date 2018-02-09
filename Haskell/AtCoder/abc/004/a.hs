main = putStrLn <$> show . (*) 2 . (read :: String -> Int) =<< getLine
