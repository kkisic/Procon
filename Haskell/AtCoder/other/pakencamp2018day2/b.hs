import Data.List
main = do
  [n, d] <- map read . words <$> getLine
  a <- reverse . sort . map read . words <$> getLine
  print $ solve a $ d - 1

solve :: [Int] -> Int -> Int
solve a d
  | length a <= d = 0
  | otherwise     = let b = drop d a
                      in (head b) + solve (tail b) d
