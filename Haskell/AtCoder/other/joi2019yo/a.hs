main = do
  [a,b,c] <- map read . words <$> getLine
  let x = div c $ a * 7 + b
      y = mod c $ a * 7 + b
      z = mod y $ a * 7
  if y < a * 7
    then print $ x * 7 + (div (y + a - 1) a)
    else print $ (x + 1) * 7

