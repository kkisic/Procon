main = do
  [c1, a] <- words <$> getLine
  [c2, b] <- words <$> getLine
  let aa = (\x -> if c1 == "W" then x * (-1) else x) . read $ a
      bb = (\x -> if c2 == "W" then x * (-1) else x) . read $ b
  print $ ((max aa bb) - (min aa bb)) `div` 15
