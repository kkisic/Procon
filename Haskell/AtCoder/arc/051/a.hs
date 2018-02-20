main = do
  [x1, y1, r] <- map read . words <$> getLine :: IO [Int]
  [x2, y2, x3, y3] <- map read . words <$> getLine :: IO [Int]
  solve x1 y1 r x2 y2 x3 y3

dist :: Int -> Int -> Int
dist x y = x * x + y * y

solve :: Int -> Int -> Int -> Int -> Int -> Int -> Int -> IO ()
solve x1 y1 r x2 y2 x3 y3
  | dist (x2-x1) (y2-y1) <= r*r && dist (x3-x1) (y2-y1) <= r*r
  && dist (x2-x1) (y3-y1) <= r*r && dist (x3-x1) (y3-y1) <= r*r = do
    putStrLn "YES"
    putStrLn "NO"
  | x2 <= x1-r && x1+r <= x3 && y2 <= y1-r && y1+r <= y3 = do
    putStrLn "NO"
    putStrLn "YES"
  | otherwise = do
    putStrLn "YES"
    putStrLn "YES"
