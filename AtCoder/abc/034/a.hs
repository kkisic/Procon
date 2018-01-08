main = do
  [x,y] <- map read . words <$> getLine :: IO [Int]
  if x < y then putStrLn "Better"
           else putStrLn "Worse"
