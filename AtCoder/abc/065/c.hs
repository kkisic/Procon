main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  if 1 < (abs $ n - m) then print 0
                       else print $ solve n m

modN = 10^9+7

fact :: Int -> Int
fact 0 = 1
fact n = (flip mod modN) . (*n) $ fact (n-1)

solve :: Int -> Int -> Int
solve n m
  | n == m    = (flip mod modN) . (*2) . (flip mod modN) . (*(fact n)) $ fact m
  | otherwise = (flip mod modN) . (*(fact n)) $ fact m
