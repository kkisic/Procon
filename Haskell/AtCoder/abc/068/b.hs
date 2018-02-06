main = do
  n <- readLn :: IO Int
  print $ head $ filter (<=n) [2^n | n <- [6,5,4,3,2,1,0]]
