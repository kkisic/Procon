main = interact $ (++"\n") . show . sum . (\x -> [1..x]) . (read :: String -> Int)
