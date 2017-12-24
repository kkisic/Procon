import Data.List
main = do
  getLine
  s <- getLine
  print $ solve s 0 0

solve :: String -> Int -> Int -> Int
solve []       _   max = max
solve ('I':as) now max
  | now + 1 > max = solve as (now + 1) (now + 1)
  | otherwise     = solve as (now + 1) max
solve ('D':as) now max = solve as (now - 1) max
