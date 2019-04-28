main = interact $ (++ "\n") . (\x -> take ((length x) - 9) x)
