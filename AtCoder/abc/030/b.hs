import Text.Printf

main = do
  [n,m] <- map read . words <$> getLine :: IO [Double]
  let n' = (if n > 12.0 then n - 12.0 else n)
      n'' = 30.0 * (n' + m / 60.0)
      m' = m * 6.0
      ans = max (n''-m') (m'-n'')
  print $ min ans $ 360.0 - ans
