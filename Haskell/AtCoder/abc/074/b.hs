main = do
  n <- readLn :: IO Int
  k <- readLn :: IO Int
  ball <- map read . words <$> getLine :: IO [Int]
  print . sum $ map (solve k) ball

solve :: Int -> Int -> Int
solve k x = if k - x < x then (k - x) * 2
                         else x * 2
