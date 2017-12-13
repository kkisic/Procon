main = interact $ (\x -> if (head x) * (last x) == 1 then "H\n" else "D\n") . map (\x -> if x == "H" then 1 else -1) . words
