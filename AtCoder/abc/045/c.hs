import Data.List
main = do
  input <- getLine
  let n = length input
      p = subsequences [1..n-1]
      ans = map (sum . split 0 input) p
  print $ sum ans

split :: Int -> String -> [Int] -> [Int]
split _ [] []     = []
split _ s []     = [read s]
split n s (x:xs) = (read $ take (x-n) s) : (split x (drop (x-n) s) xs)
