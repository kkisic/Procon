import Data.List

main = do
  n <- getLine
  s <- getLine
  print $ solve [] s 0

solve :: String -> String -> Int -> Int
solve s [] n = n
solve s t@(x:xs) n = solve (x:s) xs $ max n $ count $ intersect s t

count :: String -> Int
count = length . group . sort
