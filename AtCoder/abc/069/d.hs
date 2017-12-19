main = do
  [h, w] <- map read . words <$> getLine :: IO [Int]
  n <- readLn :: IO Int
  a <- map read . words <$> getLine :: IO [Int]
  let ans = zipWith reverseOdd [1..] . pack w . make $ a
  putStr $ unlines . map (unwords . map show) $ ans

make :: [Int] -> [Int]
make s = concat $ zipWith (\x y -> replicate x y) s [1..]

pack :: Int -> [Int] -> [[Int]]
pack w s
  | length s <= w = [s]
  | otherwise     = (take w s):(pack w $drop w s)

reverseOdd :: Int -> [Int] -> [Int]
reverseOdd n s
  | mod n 2 == 0 = s
  | otherwise    = reverse s
