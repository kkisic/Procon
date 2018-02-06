main = do
  [a,b,c,d] <- map read . words <$> getLine :: IO [Int]
  if b < c || d < a then print 0
                    else print $ (min b d) - (max a c)
