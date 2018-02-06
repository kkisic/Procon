main = do
  [a,b,c,k] <- map read . words <$> getLine :: IO [Int]
  [s,t] <- map read . words <$> getLine :: IO [Int]
  let x = a*s + b*t
      y = if s+t >= k then (s+t) * c else 0
  print $ x - y
