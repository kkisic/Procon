main = interact $ (++"\n") . show . (flip mod 24) . sum . map (read :: String -> Int) . words
