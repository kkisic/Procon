import Data.List

main = do
  [a,b,k] <- map read . words <$> getLine :: IO [Int]
  putStr $ unlines . map show . map head . group . sort $ [x | x <- [a..a+k-1], b >= x] ++ [x | x <- [b-k+1..b], a <= x]
