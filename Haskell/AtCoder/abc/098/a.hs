import Data.List
main = do
  [a, b] <- map read . words <$> getLine :: IO [Int]
  let s = [a+b, a-b, a*b]
  print $ maximum s
