main = putStrLn <$> show . (\x -> div (last x) (head x)) . fmap (read :: String -> Int) . words =<< getLine
