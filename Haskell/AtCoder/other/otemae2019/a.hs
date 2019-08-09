main = do
  [a, b] <- map read . words <$> getLine :: IO [Int]
  if a >= b
    then print 1
    else print 0
