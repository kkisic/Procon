main = interact $ (++"\n") . show . (\(x:y:z:_) -> div (x - z) (y + z)) . map (read :: String -> Int) . words
