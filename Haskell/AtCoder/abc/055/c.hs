main = interact $ (++"\n") . show . (\(s:c:_) -> if s >= div c 2 then div c 2 else ((c - s * 2) `div` 4) + s) . map (read :: String -> Int) . words
