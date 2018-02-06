main = do
  [h1, w1] <- map read . words <$> getLine :: IO [Int]
  [h2, w2] <- map read . words <$> getLine :: IO [Int]
  if h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2
    then putStrLn "YES"
    else putStrLn "NO"
