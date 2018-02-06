main = do
  input <- lines <$> getContents
  let n = (read :: String -> Double) . head $ input
      eval = last input
  putStrLn . show $ (gp 0.0 eval) / n

gp :: Double -> String -> Double
gp n [] = n
gp n (x:xs) = case x of
                'A' -> gp (n + 4.0) xs
                'B' -> gp (n + 3.0) xs
                'C' -> gp (n + 2.0) xs
                'D' -> gp (n + 1.0) xs
                'F' -> gp (n + 0.0) xs
