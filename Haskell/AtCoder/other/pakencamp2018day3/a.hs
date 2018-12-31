main = do
  [y,m,d] <- map read . words <$> getLine
  if m == 12 && d == 25
    then print $ y - 2018
    else putStrLn "NOT CHRISTMAS DAY"
