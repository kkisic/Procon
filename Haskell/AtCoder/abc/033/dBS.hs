{-# LANGUAGE BangPatterns #-}
import Data.Array.Unboxed
import Data.List

type Point = (Double, Double)
type Arr = UArray Int Double

eps = 1e-9

main = do
  n <- readLn :: IO Int
  point <- map ((\[x,y] -> (read x, read y)) . words) . lines <$> getContents :: IO [Point]
  let (eq, lt) = foldl' (solve n point) (0, 0) point
      all = div (n*(n-1)*(n-2)) 6
      gt = all*3 - (eq + lt)
  putStrLn $ show (all - eq - gt) ++ " " ++ show eq ++ " " ++ show gt

solve :: Int -> [Point] -> (Int, Int) -> Point -> (Int, Int)
solve n ps (a, b) p =
  let !al = sort $ angleList ps p
      !sl = map (+pi*2) al
      !ll = listArray (1, (n-1)*2) $ al++sl :: Arr
      !(eq, lt) = foldl' (solve' ll n) (0, 0) [1..n-1]
  in (a + eq, b + lt)

solve' :: Arr -> Int -> (Int, Int) -> Int -> (Int, Int)
solve' arr n (a, b) i =
  let !lt = upperBound (judgeLt arr $ arr ! i) 0 (2*n-1)
      !next = (arr ! (lt+1)) - (arr ! i)
      !le = if (pi/2)-eps <= next && next <= (pi/2)+eps
             then 1
             else 0
  in (a+le, b+lt-i)

angleList :: [Point] -> Point -> [Double]
angleList [] _ = []
angleList ((px, py):p) (x, y)
  | px == x && py == y = angleList p (x, y)
  | otherwise =
  let !angle = atan2 (py-y) (px-x)
      !al = angleList p (x, y)
  in angle:al

--[lb, ub)
upperBound :: (Int -> Bool) -> Int -> Int -> Int
upperBound f lb ub
  | ub - lb == 1 = lb
  | otherwise =
    let mid = div (lb + ub) 2
    in if f mid
         then upperBound f mid ub
         else upperBound f lb mid

judgeLe :: Arr -> Double -> Int -> Bool
judgeLe arr base m = (arr ! m) - base <= (pi/2)+eps

judgeLt :: Arr -> Double -> Int -> Bool
judgeLt arr base m = (arr ! m) - base < (pi/2)-eps
