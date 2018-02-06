main = do
  n <- readLn :: IO Int
  putStrLn $ solve n

solve :: Int -> String
solve n
  | n <= 59 = "Bad"
  | 60 <= n && n <= 89 = "Good"
  | 90 <= n && n <= 99 = "Great"
  | n == 100 = "Perfect"
