main = do
  a <- readLn :: IO Int
  b <- readLn :: IO Int
  c <- readLn :: IO Int
  x <- readLn :: IO Int
  let s = [(i, j, k) | i <- [0..a], j <- [0..b], k <- [0..c]]
  print $ sum $ map (solve x) s

solve :: Int -> (Int, Int, Int) -> Int
solve x (a, b, c) = if a*500 + b*100 + c*50 == x
                      then 1
                      else 0
