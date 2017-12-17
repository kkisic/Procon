main = putStrLn <$> (let f n | mod n 400 == 0 = "YES" | mod n 100 == 0 = "NO" | mod n 4 == 0 = "YES" | otherwise = "NO" in f) . (read :: String -> Int) =<< getLine
