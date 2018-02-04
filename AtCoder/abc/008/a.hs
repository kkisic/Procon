main = putStrLn <$> show . (\x -> (x !! 1) - (x !! 0) + 1) . fmap read . words =<< getLine
