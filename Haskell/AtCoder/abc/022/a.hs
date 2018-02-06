main = do
  [n,s,t] <- map read . words <$> getLine :: IO [Int]
  w <- readLn :: IO Int
  a <- map read . lines <$> getContents :: IO [Int]
  let ans = filter (==True) $ (s <= w && w <= t):(solve a w s t)
  print $ length ans

solve :: [Int] -> Int -> Int -> Int -> [Bool]
solve [] _ _ _ = []
solve (a:as) now s t = let b = s <= (now+a) && (now+a) <= t
                       in b : (solve as (now+a) s t)
