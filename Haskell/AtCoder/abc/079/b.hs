main = interact $ (++"\n") . show . head . lucas . (read :: String -> Integer)

lucas :: Integer -> [Integer]
lucas 0 = [2]
lucas 1 = [1, 2]
lucas n = let s = lucas $ n-1
            in ((s !! 0) + (s !! 1)):s
