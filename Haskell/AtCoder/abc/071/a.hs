main = interact $ (\[x, a, b] -> if abs (x - a) < abs (x - b) then "A\n" else "B\n") . map (read :: String -> Int) . words
