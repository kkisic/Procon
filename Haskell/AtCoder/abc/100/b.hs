main = do
  [d, n] <- map read . words <$> getLine :: IO [Int]
  if n == 100
    then print $ 100 ^ d * 101
    else print $ 100 ^ d * n
