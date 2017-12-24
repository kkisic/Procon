main = do
  [a,b] <- map ((\x -> if x == 1 then 14 else x) . read) . words <$> getLine :: IO [Int]
  if a > b then putStrLn "Alice"
           else if a < b then putStrLn "Bob"
                         else putStrLn "Draw"
