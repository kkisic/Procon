main = do
  [x,y] <- map read . words <$> getLine :: IO [Int]
  if 1 >= (abs $ x - y) then putStrLn "Brown"
                        else putStrLn "Alice"
