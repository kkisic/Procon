main = interact $ (++"\n") . show . (\(x:y:_) -> y * 2 - x) . map (read :: String -> Int) . words
