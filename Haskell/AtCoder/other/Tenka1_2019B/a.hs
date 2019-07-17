main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Int]
  if a < c && c < b || b < c && c < a
    then putStrLn "Yes"
    else putStrLn "No"
