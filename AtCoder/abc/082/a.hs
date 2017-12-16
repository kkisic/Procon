main = interact $ (++"\n") . show . (\(x:y:_) -> if (x + y) `mod` 2 == 0 then (x + y) `div` 2 else (+1) $ (x + y) `div` 2) . map (read :: String -> Int) . words
