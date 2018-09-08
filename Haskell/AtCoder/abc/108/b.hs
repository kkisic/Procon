main = do
  [a, b, c, d] <- map read . words <$> getLine
  let x = c - a
      y = d - b
      x1 = c - y
      y1 = d + x
      x2 = x1 - x
      y2 = y1 - y
  putStrLn . unwords . map show $ [x1, y1, x2, y2]
