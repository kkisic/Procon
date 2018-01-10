main = do
  [a,b,c,d] <- map read . words <$> getLine :: IO [Double]
  if b / a > d / c
    then putStrLn "TAKAHASHI"
    else if b / a == d / c
      then putStrLn "DRAW"
      else putStrLn "AOKI"
