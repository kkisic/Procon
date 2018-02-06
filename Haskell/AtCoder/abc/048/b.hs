main = do
  [a, b, x] <- map read . words <$> getLine :: IO [Int]
  print $ if a > 0 then (solve b x) - (solve (a - 1) x)
                   else solve b x

solve :: Int -> Int -> Int
solve n x = (+1) $ div n x
