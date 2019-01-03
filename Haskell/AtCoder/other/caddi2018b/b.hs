import Data.List
main = do
  [n,h,w] <- map read . words <$> getLine :: IO [Int]
  [a,b] <- transpose . map (map read . words) . lines <$> getContents
  let ans = filter (== True) $ zipWith (\x y -> x >= h && y >= w) a b
  print $ length ans

