main = do
  [k,s] <- map read . words <$> getLine :: IO [Int]
  print $ length [(x,y,s-x-y) | x <- [0..k], y <- [0..k], s-x-y >= 0, s-x-y <= k]
