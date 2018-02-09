main = do
  [l,x,y,s,d] <- map read . words <$> getLine :: IO [Int]
  let dist = ((d+l)-s) `mod` l
      ans1 = solve dist $ x + y
      ans2 = solve (l - dist) $ y - x
  if ans1 < ans2 || ans2 < 0
    then print ans1
    else print ans2

solve :: Int -> Int -> Double
solve x y = (realToFrac x) / (realToFrac y)
