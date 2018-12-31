main = do
  getLine
  a <- map read . lines <$> getContents
  print $ solve 0 a

solve :: Int -> [Int] -> Int
solve n [] = 0
solve n (x:xs)
  | n + x <= 2018 = 1 + solve (n+x) xs
  | otherwise     = 0
