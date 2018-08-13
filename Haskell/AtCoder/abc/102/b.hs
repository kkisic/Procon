import Data.List
main = do
  n <- getLine
  a <- map read . words <$> getLine :: IO [Int]
  let ans = map (\x -> maximum $ map (\y -> abs $ x - y) a) a
  print $ maximum ans
