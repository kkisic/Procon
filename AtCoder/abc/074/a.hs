main = interact $ (++"\n") . show . (\[x,y] -> x^2 - y) . map (read :: String -> Int) . lines
