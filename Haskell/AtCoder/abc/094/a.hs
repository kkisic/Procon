main = do
  [a,b,x] <- map read . words <$> getLine :: IO [Int]
  if a <= x && x <= a + b
    then putStrLn "YES"
    else putStrLn "NO"
