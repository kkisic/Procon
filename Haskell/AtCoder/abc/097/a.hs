main = do
  [a,b,c,d] <- map read . words <$> getLine :: IO [Int]
  if (abs $ a - b) <= d && (abs $ b - c) <= d || (abs $ a - c) <= d
    then putStrLn "Yes"
    else putStrLn "No"
