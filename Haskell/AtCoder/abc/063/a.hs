main = interact $ (\x -> if x >= 10 then "error\n" else (++"\n") . show $ x) . sum . map (read :: String -> Int) . words
