main = do
  [x,y] <- map read . words <$> getLine :: IO [Int]
  if check x == check y then putStrLn "Yes"
                        else putStrLn "No"

check :: Int -> Int
check n
  | elem n [1,3,5,7,8,10,12] = 1
  | elem n [4,6,9,11] = 2
  | otherwise = 3
