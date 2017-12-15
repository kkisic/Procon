main = do
  nx <- map (read :: String -> Int) . words <$> getLine
  a <- map (read :: String -> Int) . words <$> getLine
  let binx = int2bin $ last nx
  print . sum $ zipWith (*) binx a

int2bin :: Int -> [Int]
int2bin 0 = []
int2bin n = n `mod` 2 : int2bin (n `div` 2)
