main = do
  [l,h] <- map read . words <$> getLine :: IO [Int]
  n <- readLn :: IO Int
  a <- map read . lines <$> getContents :: IO [Int]
  putStr $ unlines . map (show . solve l h) $ a

solve :: Int -> Int -> Int -> Int
solve l h a
  | l > a            = l - a
  | l <= a && a <= h = 0
  | otherwise        = negate 1
