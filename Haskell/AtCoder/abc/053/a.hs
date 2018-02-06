main = interact $ (\x -> if x < 1200 then "ABC\n" else "ARC\n") . (read :: String -> Int)
