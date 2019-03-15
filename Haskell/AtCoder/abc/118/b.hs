import Data.List
main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  input <- map (tail . map read . words) . lines <$> getContents :: IO [[Int]]
  print . length $ foldr1 intersect input
