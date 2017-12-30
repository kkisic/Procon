main = do
  n <- readLn :: IO Int
  a <- map read . words <$> getLine :: IO [Int]
  let ave = div (sum a) n
      ave' = ave + 1
  print $ min (cost ave a) (cost ave' a)

cost :: Int -> [Int] -> Int
cost n a = sum $ map (\x -> (x - n)^2) a
