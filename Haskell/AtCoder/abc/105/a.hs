main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  if mod n k == 0
    then print 0
    else print 1
