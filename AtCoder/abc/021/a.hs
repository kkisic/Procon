main = do
  n <- readLn :: IO Int
  let ans = solve n
  print $ length ans
  putStr $ unlines . map show $ ans

solve :: Int -> [Int]
solve 0 = []
solve n
  | n >= 8 = 8 : (solve $ n-8)
  | n >= 4 = 4 : (solve $ n-4)
  | n >= 2 = 2 : (solve $ n-2)
  | n >= 1 = 1 : (solve $ n-1)
