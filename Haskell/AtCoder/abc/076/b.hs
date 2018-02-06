main = do
  n <- readLn :: IO Int
  k <- readLn :: IO Int
  print $ solve n k 1

solve :: Int -> Int -> Int -> Int
solve 0 _ ans = ans
solve n k ans
  | ans > k   = solve (n-1) k $ ans + k
  | otherwise = solve (n-1) k $ ans * 2
