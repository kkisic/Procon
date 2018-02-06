main = do
  getLine
  p <- map (map read . words) . lines <$> getContents :: IO[[Int]]
  let ans = maximum . concat $ map (solve p) p
  print ans

solve :: [[Int]] -> [Int] -> [Double]
solve ps p = map (dist p) ps

dist :: [Int] -> [Int] -> Double
dist [a,b] [c,d] = sqrt . realToFrac $ ((^2) $ abs (c-a)) + ((^2) $ abs (d-b))
