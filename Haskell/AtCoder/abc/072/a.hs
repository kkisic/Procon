main = interact $ (++"\n") . show . (\[x,y] -> if x > y then x - y else 0) . map (read :: String -> Int) . words
