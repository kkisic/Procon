main = do
  [a,b] <- map read . words <$> getLine :: IO [Int]
  let x = max a b
      y = min a b
  print $ solve x y

solve :: Int -> Int -> Int
solve x y
  | x - y >= 10 = 1 + solve (x-10) y
  | x - y == 9 = 2 + solve (x-9) y
  | x - y == 8 = 3 + solve (x-8) y
  | x - y == 7 = 3 + solve (x-7) y
  | x - y == 6 = 2 + solve (x-6) y
  | x - y == 5 = 1 + solve (x-5) y
  | x - y == 4 = 2 + solve (x-4) y
  | x - y == 3 = 3 + solve (x-3) y
  | x - y == 2 = 2 + solve (x-2) y
  | x - y == 1 = 1 + solve (x-1) y
  | otherwise = 0
