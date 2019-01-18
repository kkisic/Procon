import Data.List

main = do
  n <- readLn :: IO Int
  a <- sortBy (\x y -> compare y x) . map read . words <$> getLine :: IO [Int]
  let (x, y) = solve a ([], [])
  print $ sum x - sum y

solve :: [Int] -> ([Int], [Int]) -> ([Int], [Int])
solve [] (x, y) = (x, y)
solve (a:[]) (x, y) = (a:x, y)
solve (a:b:as) (x, y) = solve as (a:x, b:y)
