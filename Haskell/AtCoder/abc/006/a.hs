main = putStrLn <$> (\x -> if mod x 3 == 0 then "YES" else "NO") . read =<< getLine
