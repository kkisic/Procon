main = do
  n <- readLn :: IO Int
  input <- map (map read . words) . lines <$> getContents :: IO [[Int]]
  print $ solve 1 1 input

solve :: Int -> Int -> [[Int]] -> Int
solve t a [] = t + a
solve t a ([x,y]:s)
  | x < t || y < a = let multi = max (div' t x) (div' a y)
                     in solve (x * multi) (y * multi) s
  | otherwise = solve x y s

div' :: Int -> Int -> Int
div' x y = if mod x y == 0 then div x y
                           else (div x y) + 1
