main = do
  [a,b,h] <- map read . lines <$> getContents :: IO [Int]
  print $ ((a + b) * h) `div` 2
