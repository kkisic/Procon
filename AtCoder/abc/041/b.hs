main = do
  input <- map read . words <$> getLine :: IO [Int]
  print $ foldl1 (\x y -> flip mod (10^9+7) $ x * y) input
