main = interact $ (++"\n") . show . (\(x:y:_) -> (y * 1900 + (x - y) * 100) * 2^y) . map (read :: String -> Int) . words
