main = do
  n <- (read :: String -> Int) <$> getLine
  getLine
  takoyaki <- map (read :: String -> Int) . words <$> getLine
  getLine
  customer <- map (read :: String -> Int) . words <$> getLine
  if solve n takoyaki customer
    then putStrLn "yes"
    else putStrLn "no"

solve :: Int -> [Int] -> [Int] -> Bool
solve _ _ [] = True
solve _ [] _ = False
solve t tako@(a:as) cus@(b:bs)
  | a <= b && a + t >= b = solve t as bs
  | otherwise            = solve t as cus
