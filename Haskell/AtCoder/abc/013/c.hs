main = do
  [n,h] <- map read . words <$> getLine :: IO [Int]
  [a,b,c,d,e] <- map read . words <$> getLine :: IO [Int]
  let x = map (solve h n b d e) [0..n]
  print $ minimum $ map (solve' a c) x

solve :: Int -> Int -> Int -> Int -> Int -> Int -> (Int, Int)
solve h n b d e x = let s = e * n - h - (b + e) * x
                        t = d + e
                    in (x, max 0 $ (+1) $ div s t)

solve' :: Int -> Int -> (Int, Int) -> Int
solve' a c (x, y) = a * x + c * y
