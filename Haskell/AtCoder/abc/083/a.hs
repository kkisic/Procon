main = do
  [a,b,c,d] <- map read . words <$> getLine :: IO [Int]
  if a + b < c + d then putStrLn "Right"
                   else if a + b == c + d
                          then putStrLn "Balanced"
                          else putStrLn "Left"
