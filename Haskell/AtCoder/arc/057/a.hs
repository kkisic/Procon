tar = 2*10^12

main = do
  [a, k] <- map read . words <$> getLine :: IO [Int]
  print $ solve a k

solve :: Int -> Int -> Int
solve a 0 = tar - a
solve a k
  | a >= tar = 0
  | otherwise = 1 + solve (a*(k+1)+1) k
