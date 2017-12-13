import Data.List
main = do
  nk <- map (read :: String -> Int) . words <$> getLine
  card <- reverse . sort . map (read :: String -> Int) . words <$> getLine
  putStrLn . show . length $ solve 0 0 (last nk) card

solve :: Int -> Int -> Int -> [Int] -> [Int]
solve n x k []      = []
solve n x k s@(y:ys)
  | n >= k        = solve (n-x) 0 k s
  | n + sum s < k = s
  | otherwise     = solve (n+y) y k ys
