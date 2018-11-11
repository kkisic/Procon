main = do
  n <- readLn
  print $ solve n 111

solve :: Int -> Int -> Int
solve x y
  | x <= y = y
  | otherwise = solve x $ y + 111
