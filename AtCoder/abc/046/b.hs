main = do
  [n, k] <- map read . words <$> getLine :: IO [Integer]
  print $ solve n k

solve :: Integer -> Integer -> Integer
solve n k
  | n > 1 = (k-1) * (solve (n-1) k)
  | otherwise = k
