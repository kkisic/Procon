main = do
  [h, w] <- map read . words <$> getLine :: IO [Int]
  print $ (h-1)*w + (w-1)*h
