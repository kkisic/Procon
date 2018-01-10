import Data.List

main = do
  getLine
  [x,y] <- map read . words <$> getLine :: IO [Int]
  a <- map read . words <$> getLine :: IO [Int]
  b <- map read . words <$> getLine :: IO [Int]
  print $ solve 0 0 x y a b

solve :: Int -> Int -> Int -> Int -> [Int] -> [Int] -> Int
solve 0 _   _ _ [] _ = 0
solve 1 _   _ _ _ [] = 0
solve 0 now x y (a:as) b
  | now <= a   = solve 1 (a+x) x y as b
  | otherwise = solve 0 now x y as b
solve 1 now x y a (b:bs)
  | now <= b   = 1 + (solve 0 (b+y) x y a bs)
  | otherwise = solve 1 now x y a bs
