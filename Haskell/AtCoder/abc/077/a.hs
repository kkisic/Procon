main = interact $ (\x -> if x == reverse x then "YES\n" else "NO\n") . concat . lines
