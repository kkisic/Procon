main = interact $ (\[x, y] -> if mod x 3 == 0 || mod y 3 == 0 || mod (x+y) 3 == 0 then "Possible\n" else "Impossible\n") . map (read :: String -> Int) . words
