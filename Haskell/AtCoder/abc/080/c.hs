main = do
  nn <- (read :: String -> Int) <$> getLine
  input <- map (map (read :: String -> Int) . words) . lines <$> getContents
  let n = [0,1]
      joi = tail [[a,b,c,d,e,f,g,h,i,j] | a <- n, b <- n, c <- n, d <- n, e <- n, f <- n, g <- n, h <- n, i <- n, j <- n]
      ff = take nn input
      pp = drop nn input
  putStrLn . show . maximum $ map (\x -> solve' pp (solve ff x)) joi

solve :: [[Int]] -> [Int] -> [Int]
solve ff joi = map (sum . zipWith (\x y -> if x == y && x == 1 then 1 else 0) joi) ff

solve' :: [[Int]] -> [Int] -> Int
solve' pp cc = sum $ zipWith (!!) pp cc
