main = do
  n <- readLn :: IO Int
  k <- readLn :: IO Int
  x <- readLn :: IO Int
  y <- readLn :: IO Int
  if n <= k then print $ x * n
            else print $ x * k + (n - k) * y
