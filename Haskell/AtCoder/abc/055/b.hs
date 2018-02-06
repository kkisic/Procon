main = interact $ (++"\n") . show . (\x -> foldl1 (\y z -> mod (y * z) 1000000007) [1..x]) . (read :: String -> Int)
