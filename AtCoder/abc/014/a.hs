main = putStrLn <$> show . (\x -> if 0 == last x then 0 else (x !! 1) - (x !! 2)) . (\x -> x ++ [mod (head x) (last x)]) . fmap (read :: String -> Int) . lines =<< getContents
