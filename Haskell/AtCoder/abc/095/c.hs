main = do
  [a,b,c,x,y] <- map read . words <$> getLine :: IO [Int]
  let aa = min a $ c * 2
      bb = min b $ c * 2
      ab = min (a + b) $ c * 2
  if x < y
    then print $ ab * x + (y - x) * bb
    else print $ ab * y + (x - y) * aa
