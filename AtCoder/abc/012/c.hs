main = do
  n <- (read :: String -> Int) <$> getLine
  putStrLn $ init . unlines . map printPair . solve $ 2025 - n

solve :: Int -> [(Int, Int)]
solve n = [(x, y) | x <- [1..9], y <- [1..9], x * y == n]

printPair :: (Int, Int) -> String
printPair (x, y) = show x ++ " x " ++ show y
