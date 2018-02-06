main = interact $ (\x -> if x == reverse x then "Yes\n" else "No\n") . init
