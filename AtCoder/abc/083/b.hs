import Data.Char
main = do
  [n,a,b] <- map read . words <$> getLine :: IO [Int]
  let x = map (solve a b) [1..n]
  print $ sum $ zipWith (*) x [1..n]

solve :: Int -> Int -> Int -> Int
solve a b n = let s = sum . map digitToInt . show $ n
              in if a <= s && s <= b then 1 else 0
