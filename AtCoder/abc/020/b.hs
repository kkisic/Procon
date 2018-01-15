main = do
  [a, b] <- words <$> getLine
  let x = read $ a++b :: Int
  print $ x * 2
