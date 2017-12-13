main = do
  n <- readLn
  print $ solve 1 0 n

solve :: Int -> Int -> Int -> Int
solve i sum n
  | i + sum >= n = i
  | otherwise    = solve (i+1) (sum+i) n
