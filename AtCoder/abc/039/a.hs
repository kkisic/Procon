main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Int]
  print $ a * b * 2 + b * c * 2 + c * a * 2
