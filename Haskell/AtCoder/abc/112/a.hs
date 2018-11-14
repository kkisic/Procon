main = do
  n <- readLn
  solve n

solve :: Int -> IO ()
solve 1 = putStrLn "Hello World"
solve 2 = do
  a <- readLn
  b <- readLn
  print $ a + b
