main = do
  [a,b,c] <- map read . words <$> getLine :: IO [Int]
  if judge a b c then putStrLn "Yes"
                 else putStrLn "No"

judge :: Int -> Int -> Int -> Bool
judge a b c = a + b == c || a + c == b || b + c == a
