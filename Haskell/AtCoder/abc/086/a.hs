main = do
  [a,b] <- map read . words <$> getLine :: IO [Int]
  if odd $ a * b
    then putStrLn "Odd"
    else putStrLn "Even"
