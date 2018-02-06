main = do
  a <- readLn :: IO Int
  b <- readLn :: IO Int
  n <- readLn :: IO Int
  let x = lcm a b
  print $ solve x n

solve :: Int -> Int -> Int
solve l x
  | l >= x    = l
  | otherwise = if mod x l == 0 then l * (div x l)
                                else l * ((+1) $ div x l)
