main = putStrLn <$> (\x -> if (head x) `mod` (last x) == 0 then "YES" else "NO") . map (read :: String -> Int) . words =<< getLine
