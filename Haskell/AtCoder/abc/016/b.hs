main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Int]
  solve a b c

solve :: Int -> Int -> Int -> IO ()
solve a b c
  | a+b == c && a-b == c = putStrLn "?"
  | a+b == c = putStrLn "+"
  | a-b == c = putStrLn "-"
  | otherwise = putStrLn "!"
