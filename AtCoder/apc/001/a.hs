main = do
  [x,y] <- map read . words <$> getLine :: IO [Int]
  if mod x y /= 0
    then print x
    else print $ negate 1
