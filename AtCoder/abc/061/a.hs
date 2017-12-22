main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Int]
  if a <= c && c <= b then putStrLn "Yes"
                      else putStrLn "No"
