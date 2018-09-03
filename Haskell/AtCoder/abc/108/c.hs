main = do
  [n, k] <- map read . words <$> getLine
  let x = div n k
      y = (n + div k 2) `div` k
  if mod k 2 == 0
    then print $ (x ^ 3) + (y ^ 3)
    else print $ x ^ 3



