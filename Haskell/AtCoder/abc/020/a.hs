main = interact $ (\x -> if x == 1 then "ABC\n" else "chokudai\n") . (read :: String -> Int)
