main = putStrLn <$> show . (\x -> 1 + mod x 12) . read =<< getLine
