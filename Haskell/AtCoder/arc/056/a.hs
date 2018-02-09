main = do
  [a,b,k,l] <- map read . words <$> getLine :: IO [Int]
  print $ solve a b k l

solve :: Int -> Int -> Int -> Int -> Int
solve a b k l
  | a * l < b = a * k
  | otherwise =
  let s = div k l
      t = k - s * l
  in if t * a < b
       then b * s + a * t
       else b * (s+1)
