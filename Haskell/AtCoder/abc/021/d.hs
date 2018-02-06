modN = 10^9+7

main = do
  n <- readLn :: IO Int
  k <- readLn :: IO Int
  if k == 1
    then print n
    else do
      let x = reverse [1..n]
          y = solve (k-2) n 0 0
          z = zipWith (\a b -> flip mod modN $ a * b) x y
      print $ foldl1 (\a b -> flip mod modN $ a + b) z

solve :: Int -> Int -> Int -> Int -> [Int]
solve k n 0 kcx = 1 : (solve k n 1 1)
solve k n x kcx
  | n == x = []
  | otherwise =
  let xr = x |^ (10^9+5)
      kcx' = flip mod modN $ kcx * xr
      kcx'' = flip mod modN $ kcx' * (k+x)
  in kcx'' : (solve k n (x+1) kcx'')

--x^n (mod modN)
(|^) :: Int -> Int -> Int
(|^) x n
  | n == 0    = 1
  | even n    = (mod (x * x) modN) |^ (n `div` 2)
  | otherwise = (flip mod modN) . (*x) $ x |^ (n - 1)

--x! (mod modN)
fact :: Int -> Int
fact n
  | n == 0    = 1
  | otherwise = (flip mod modN) . (*n) $ fact (n-1)
