main = do
  [n,a,b] <- map read . words <$> getLine :: IO [Int]
  let diff = abs $ a - b
  if even diff
    then putStrLn "Alice"
    else putStrLn "Borys"
