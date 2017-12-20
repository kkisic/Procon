main = do
  [x,a,b] <- map read . words <$> getLine :: IO [Int]
  if a >= b then putStrLn "delicious"
            else if x + a >= b then putStrLn "safe"
                              else putStrLn "dangerous"
