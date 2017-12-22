main = do
  [a, b, c] <- map read . words <$> getLine :: IO [Int]
  let table = [mod (a * n) b | n <- [1..b]]
  if elem c table then putStrLn "YES"
                  else putStrLn "NO"
