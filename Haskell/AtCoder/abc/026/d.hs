main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Double]
  print $ bisection 0 0 200 a b c

f :: Double -> Double -> Double -> Double -> Double
f a b c t = a * t + b * (sin $ c * t * pi)

check :: Double -> Double -> Double -> Double -> Int
check a b c t = if (1 / (10.0^6)) >= abs ((f a b c t) - 100)
                  then 0
                  else if (f a b c t) > 100
                         then 1
                         else negate 1

bisection :: Int -> Double -> Double -> Double -> Double -> Double -> Double
bisection 200 l r a b c = l
bisection n   l r a b c
  | l == r = l
  | otherwise = let m = (l + r) / 2
                    ft = check a b c m
                in case ft of
                     0    -> m
                     1    -> bisection (n+1) l m a b c
                     (-1) -> bisection (n+1) m r a b c
