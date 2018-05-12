import Data.List
main = do
  x <- readLn
  let a = [1..x]
      b = 2 : [2..x]
      c = sort $ concat $ map (f x a) b
  print $ last c

f :: Int -> [Int] -> Int -> [Int]
f x [] n = []
f x (a:as) n
  | a ^ n <= x = (a^n) : f x as n
  | otherwise  = f x as n
