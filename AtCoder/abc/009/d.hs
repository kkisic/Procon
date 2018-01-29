import Data.Bits
import Data.List

main = do
  [k, m] <- map read . words <$> getLine :: IO [Int]
  a <- reverse . map read . words <$> getLine :: IO [Int]
  c <- map read . words <$> getLine :: IO [Int]
  if k >= m
    then print $ (reverse a) !! (m-1)
    else do
      let cM = c:(init $ identify k)
          cM' = power cM $ m - k
      print $ head $ cM' |*/ a

type Vector a = [a]
type Matrix a = [Vector a]

--Vector
(/+/) :: Vector Int -> Vector Int -> Vector Int
(/+/) xs ys = zipWith xor xs ys

(/*/) :: Vector Int -> Vector Int -> Int
(/*/) xs ys = foldl1 xor $ zipWith (.&.) xs ys

zeroV :: Int -> Vector Int
zeroV n = take n $ repeat 0

--Matrix
(|+|) :: Matrix Int -> Matrix Int -> Matrix Int
(|+|) x y = zipWith (/+/) x y

(|*|) :: Matrix Int -> Matrix Int -> Matrix Int
(|*|) xss yss = [[xs /*/ ys | ys <- (transpose yss)] | xs <- xss]

(|*/) :: Matrix Int -> Vector Int -> Vector Int
(|*/) m v = map (v/*/)  m

identify :: Int -> Matrix Int
identify n = [take n $ f x | x <- [0..n-1]]
  where f x = replicate x 0 ++ [2^32-1] ++ repeat 0

power :: Matrix Int -> Int -> Matrix Int
power mat n = loop (n-1) mat mat
  where loop 0 _ r = r
        loop n x r = loop (div n 2) (x |*| x) r'
          where r' = if odd n then r |*| x else r
