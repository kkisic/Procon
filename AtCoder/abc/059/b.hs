main = do
  [a, b] <- map read . lines <$> getContents :: IO [Integer]
  if a > b then putStrLn "GREATER"
           else if a == b then putStrLn "EQUAL"
                          else putStrLn "LESS"
