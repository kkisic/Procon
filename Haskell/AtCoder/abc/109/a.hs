main = do
  [a, b] <- map read . words <$> getLine
  if mod (a * b) 2 == 0
    then putStrLn "No"
    else putStrLn "Yes"
