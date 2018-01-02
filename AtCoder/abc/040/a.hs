main = do
  [n,x] <- map read . words <$> getLine :: IO [Int]
  print $ min (n-x) (x-1)
