main = do
  [w,h] <- map read . words <$> getLine :: IO [Int]
  if div w 4 == div h 3 then putStrLn "4:3"
                        else putStrLn "16:9"
