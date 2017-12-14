main = interact $ (++"\n") . show . (\x -> x * 800 - (div x 15) * 200) . (read :: String -> Int)
