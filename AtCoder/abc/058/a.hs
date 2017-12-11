main = interact $ (\x -> if (x!!1) - (x!!0) == (x!!2) - (x!!1) then "YES\n" else "NO\n") . map (read :: String -> Int) . words
