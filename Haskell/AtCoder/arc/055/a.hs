main = do
  n <- readLn :: IO Int
  putStrLn $ "1" ++ replicate (n-1) '0' ++ "7"
