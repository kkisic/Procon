main = do
  [a, b] <- map read . words <$> getLine :: IO [Int]
  if mod b a == 0
    then print $ div b a
    else print . (+1) $ div b a
