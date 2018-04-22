import Data.List

main = do
  [n, x] <- map read . words <$> getLine :: IO [Int]
  m <- sort . map read . lines <$> getContents :: IO [Int]
  let s = sum m
      remain = x - s
      ans = (length m) + (div remain $ head m)
  print ans
