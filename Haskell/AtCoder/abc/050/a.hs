main = do
  [a, b, c] <- words <$> getLine
  if b == "+" then print $ (read a) + (read c)
              else print $ (read a) - (read c)
