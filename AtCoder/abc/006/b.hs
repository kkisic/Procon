main = do
  n <- (read :: String -> Int) <$> getLine
  putStrLn . show $ head . tribo $ n

tribo :: Int -> [Int]
tribo 1 = [0]
tribo 2 = [0, 0]
tribo 3 = [1, 0, 0]
tribo n =
  let t = tribo (n-1)
    in (((t !! 0) + (t !! 1) + (t !! 2)) `mod` 10007):t
