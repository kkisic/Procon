main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Int]
  let m = min a b
      count = div c m
      remain = mod c m
  print $ count + (div remain $ max a b)
