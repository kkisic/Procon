main = do
  [a,d] <- map read . words <$> getLine :: IO [Int]
  print $ max ((a+1)*d) (a*(d+1))
