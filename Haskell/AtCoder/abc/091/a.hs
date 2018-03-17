main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Int]
  if a + b >= c
    then putStrLn "Yes"
    else putStrLn "No"
