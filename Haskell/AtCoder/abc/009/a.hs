main = putStrLn <$> show . (\x -> div (1 + x) 2) . read =<< getLine
