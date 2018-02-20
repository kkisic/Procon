main = do
  k <- readLn :: IO Int
  let (a, b) = solve k (1, 0)
  putStrLn $ show a ++ " " ++ show b

solve :: Int -> (Int, Int) -> (Int, Int)
solve (-1) ans = ans
solve k (a, b) = solve (k-1) (a+b, a)
