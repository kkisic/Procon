main = do
  [w,h,n] <- map read . words <$> getLine :: IO [Int]
  input <- map (map read . words) . lines <$> getContents :: IO [[Int]]
  let (l, r, b, t) = solve (0, w, 0, h) input
      s = (r - l) * (t - b)
  print $ if r > l && t > b then s else 0

solve :: (Int, Int, Int, Int) -> [[Int]] -> (Int, Int, Int, Int)
solve (l, r, b, t) [] = (l, r, b, t)
solve (l, r, b, t) ([x, y, a]:s)
  | a == 1 && l < x = solve (x, r, b, t) s
  | a == 2 && x < r = solve (l, x, b, t) s
  | a == 3 && b < y = solve (l, r, y, t) s
  | a == 4 && y < t = solve (l, r, b, y) s
  | otherwise       = solve (l, r, b, t) s
