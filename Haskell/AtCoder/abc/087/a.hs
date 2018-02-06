main = do
  x <- readLn :: IO Int
  a <- readLn :: IO Int
  b <- readLn :: IO Int
  let c = div (x-a) b
  print $ x - (a + b * c)
