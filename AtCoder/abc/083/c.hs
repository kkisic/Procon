main = do
  [x,y] <- map read . words <$> getLine :: IO [Int]
  print $ (+1) $ solve x y

solve :: Int -> Int -> Int
solve x y = if x * 2 <= y then 1 + solve (x*2) y
                          else 0
