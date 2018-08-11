main = do
  n <- readLn
  if n == 0 then putStrLn "0"
            else putStrLn . reverse $ solve n

solve :: Int -> String
solve 0 = []
solve n
  | mod n 2 == 0 = '0': (solve $ div n (-2))
  | otherwise  = '1': (solve $ div (n-1) (-2))
