eps = 1e-8

main = do
  p <- readLn :: IO Double
  print $ f (bisection 0 p 0 p) p

bisection :: Int -> Double -> Double -> Double -> Double
bisection 100 p l r = l
bisection n   p l r
  | l == r = l
  | otherwise = let m1 = (l + r) / 2
                    m2 = m1 + eps
                    x1 = f m1 p
                    x2 = f m2 p
                in if x1 > x2
                     then bisection (n+1) p m1 r
                     else bisection (n+1) p l m1

f :: Double -> Double -> Double
f m p = m + p / (2.0**(m/1.5))
