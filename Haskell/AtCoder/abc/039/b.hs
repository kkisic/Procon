main = do
  x <- readLn :: IO Int
  print $ solve x 1

solve :: Int -> Int -> Int
solve x i = if i^4 == x then i
                        else solve x $ i + 1
