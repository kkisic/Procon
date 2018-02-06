main = interact $ show . (\x -> min (product . init $ x) (last x)) . (map (read :: String -> Int)) . words
