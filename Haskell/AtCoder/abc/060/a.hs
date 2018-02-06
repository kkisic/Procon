main = interact $ (\[x, y, z] -> if last x == head y && last y == head z then "YES\n" else "NO\n") . words
