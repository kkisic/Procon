main = do
  s <- getLine
  print $ length . filter (== False) $ zipWith (\x y -> x == y) s "CODEFESTIVAL2016"
