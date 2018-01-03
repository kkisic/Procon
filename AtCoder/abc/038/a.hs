main = interact $ (\x -> if x == 'T' then "YES\n" else "NO\n") . last . init
