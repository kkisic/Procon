main = interact $ (++"\n") . show . last . (\x -> [n^2 | n <- [1..10^5], n^2 <= x]) . (read :: String -> Int)
