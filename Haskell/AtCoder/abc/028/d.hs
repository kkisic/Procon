import Text.Printf

main = do
  [n,k] <- map read . words <$> getLine :: IO [Double]
  let x = ((n-1)^3 + 3*(n-k)^2 + 3*(k-1)^2) / (n^3)
  putStrLn $ printf "%.9f" $ 1.0 - x
