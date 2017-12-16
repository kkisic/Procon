main = interact $ (++"\n") . (\(x:y:z:zs) -> if x == y then z else if x == z then y else x) . words
