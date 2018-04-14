main = do
  [n,m,x] <- map read . words <$> getLine :: IO [Int]
  a <- map read . words <$> getLine :: IO [Int]
  let s = length . filter (> x) $ a
      t = length . filter (< x) $ a
  print $ min s t
