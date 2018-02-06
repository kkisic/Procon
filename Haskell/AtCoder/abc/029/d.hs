main = do
  n <- readLn :: IO Int
  print $ (f n) + (g 1 n) + (g 2 n) + (g 3 n) + (g 4 n) + (g 5 n) + (g 6 n) + (g 7 n) + (g 8 n)

f :: Int -> Int
f n = let a = div n 10
          b = mod n 10
          c = if b >= 2 then 1 else b
      in a + c

g :: Int -> Int -> Int
g x n
  | n < 10^x = 0
  | otherwise = let a = div n (10*10^x)
                    b = mod n (10*10^x)
                    c = if b >= 2*10^x then 10^x
                                       else if b > (10^x-1) then b - (10^x-1) else 0
                in (a*10^x) + c
