main = putStrLn <$> show . (\x -> flip (div) x $ (*) 10000 $ sum [1..x]) . (read :: String -> Int) =<< getLine
