main = do
  n <- (read :: String -> Int) <$> getLine
  let h = n `div` 3600
      m = (n - 3600 * h) `div` 60
      s = n - (3600 * h + 60 * m)
  putStrLn $ toString h ++ ":" ++ toString m ++ ":" ++ toString s

toString :: Int -> String
toString n = if (length . show $ n) < 2
                then "0" ++ show n
                else show n
