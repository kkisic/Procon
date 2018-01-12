main = do
  [n,a,b] <- map read . words <$> getLine :: IO [Int]
  input <- map ((\[x,y] -> (x, read y)) . words) . lines <$> getContents :: IO [(String, Int)]
  let ans = foldl (move a b) 0 input
  if ans == 0
    then print 0
    else if ans > 0
           then putStrLn $ "East " ++ show ans
           else putStrLn $ "West " ++ show (abs ans)

move :: Int -> Int -> Int -> (String, Int) -> Int
move a b x (s, d)
  | d < a = move a b x (s, a)
  | d > b = move a b x (s, b)
  | otherwise = if s == "East"
                  then x + d
                  else x - d
