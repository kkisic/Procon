main = do
  [a, b] <- map read . words <$> getLine
  if a <= 8 && b <= 8
    then putStrLn "Yay!"
    else putStrLn ":("
