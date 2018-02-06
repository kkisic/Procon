import Data.Array.Unboxed
import Data.List

main = do
  n <- readLn :: IO Int
  a <- map read . words <$> getLine :: IO [Int]
  let ans = last . sort $ map (solve n a) [1..n]
  print $ fst ans

solve :: Int -> [Int] -> Int -> (Int, Int)
solve n a t = let all = map (solve' a t) [i | i <- [1..n], i /= t]
              in maxA (head all) all

solve' :: [Int] -> Int -> Int -> (Int, Int)
solve' a t ao
  | t < ao  = let a' = drop (t-1) $ take ao a
                  (t', ao') = split a' ([], [])
              in (sum t', sum ao')
  | t >= ao = let a' = drop (ao-1) $ take t a
                  (t', ao') = split a' ([], [])
              in (sum t', sum ao')

split :: [Int] -> ([Int], [Int]) -> ([Int], [Int])
split [] (a, b) = (a, b)
split (x:[]) (a, b) = (x:a, b)
split (x:y:ys) (a, b) = split ys (x:a, y:b)

maxA :: (Int, Int) -> [(Int, Int)] -> (Int, Int)
maxA (t, ao) [] = (t, ao)
maxA (t, ao) ((x, y):s)
  | ao < y    = maxA (x, y) s
  | otherwise = maxA (t, ao) s
