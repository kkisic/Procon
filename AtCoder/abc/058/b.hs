main = do
  o <- getLine
  e <- getLine
  putStrLn $ (concat . zipWith (\x y -> [x, y]) o $ e) ++ if length o == length e then "" else [last o]
