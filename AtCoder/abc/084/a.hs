main = interact $ (++"\n") . show . (\x -> (24 - x) + 24) . (read :: String -> Int) . init
