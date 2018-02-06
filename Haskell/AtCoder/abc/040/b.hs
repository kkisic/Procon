import Data.List

main = do
  n <- readLn :: IO Int
  let ans = minimum $ map (solve n) [1..(div n 2 + 1)]
  print ans

solve :: Int -> Int -> Int
solve n i = let x = div n i
                m = mod n i
            in (abs $ i - x) + m
