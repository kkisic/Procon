main = putStrLn <$> show . maximum . fmap (read :: String -> Int) . words =<< getLine
