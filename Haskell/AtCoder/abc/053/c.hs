main = do
  x <- readLn :: IO Int
  let c = div x 11
      c' = mod x 11
  print $ c * 2 + f c'

f x
  | x > 6  = 2
  | x == 0 = 0
  | otherwise = 1
