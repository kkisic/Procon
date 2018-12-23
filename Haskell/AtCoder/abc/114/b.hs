main = do
  s <- getLine
  print $ solve 1000 s

solve :: Int -> String -> Int
solve x s
  | length s >= 3 = let y = read $ take 3 s :: Int
                      in solve (min x . abs $ 753 - y) $ tail s
  | otherwise = x
