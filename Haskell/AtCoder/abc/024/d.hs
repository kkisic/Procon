modN = 10^9+7

main = do
  a <- readLn :: IO Int
  b <- readLn :: IO Int
  c <- readLn :: IO Int
  let ab = flip mod modN $ a * b
      bc = flip mod modN $ b * c
      ac = flip mod modN $ a * c
      c1 = flip mod modN $ modN + bc - ab
      r1 = flip mod modN $ modN + bc - ac
      cr = flip mod modN $ modN + ac - bc + ab
      crR = cr |^ (10^9+5)
      cc = flip mod modN $ c1 * crR
      rr = flip mod modN $ r1 * crR
  putStrLn $ show rr ++ " " ++ show cc

--x^n (mod modN)
(|^) :: Int -> Int -> Int
(|^) x n
  | n == 0    = 1
  | even n    = (mod (x * x) modN) |^ (n `div` 2)
  | otherwise = (flip mod modN) . (*x) $ x |^ (n - 1)
