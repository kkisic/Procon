import Data.List

type Vector a = [a]
type Matrix a = [Vector a]

main = do
  return ()

--Vector
(*/) :: Num a => a -> Vector a -> Vector a
(*/) n xs = map (*n) xs
infixl 7 */

(/+/) :: Num a => Vector a -> Vector a -> Vector a
(/+/) xs ys = zipWith (+) xs ys
infixl 6 /+/

(/-/) :: Num a => Vector a -> Vector a -> Vector a
(/-/) xs ys = zipWith (-) xs ys
infixl 6 /-/

(/*/) :: Num a => Vector a -> Vector a -> a
(/*/) xs ys = sum $ zipWith (*) xs ys
infixl 7 /*/

norm :: Floating a => Vector a -> a
norm v = sqrt $ v /*/ v

zeroV :: Num a => Int -> Vector a
zeroV n = take n $ repeat 0

--Matrix
ref :: Num a => Int -> Int -> Matrix a -> a
ref r c mat = (mat !! r) !! c

(*|) :: Num a => a -> Matrix a -> Matrix a
(*|) n mat = map (n */) mat
infixl 7 *|

(|+|) :: Num a => Matrix a -> Matrix a -> Matrix a
(|+|) x y = zipWith (/+/) x y
infixl 6 |+|

(|-|) :: Num a => Matrix a -> Matrix a -> Matrix a
(|-|) x y = zipWith (/-/) x y
infixl 6 |-|

(|*|) :: Num a => Matrix a -> Matrix a -> Matrix a
(|*|) xss yss = [[xs /*/ ys | ys <- (transpose yss)] | xs <- xss]
infixl 7 |*|

(|*/) :: Matrix Int -> Vector Int -> Vector Int
(|*/) m v = map (v/*/)  m
infixl 7 |*|

zeroM :: Num a => Int -> Int -> Matrix a
zeroM r c = take r $ repeat $ zeroV c

identify :: Num a => Int -> Matrix a
identify n = [take n $ f x | x <- [0..n-1]]
  where f x = replicate x 0 ++ [1] ++ repeat 0

power :: Num a => Matrix a -> Int -> Matrix a
power mat n = loop (n-1) mat mat
  where loop 0 _ r = r
        loop n x r = loop (div n 2) (x |*| x) r'
          where r' = if odd n then r |*| x else r
