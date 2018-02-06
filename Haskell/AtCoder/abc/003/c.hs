import Data.List

main = do
  input <- lines <$> getContents
  let nk = map (read :: String -> Int) . words . head $ input
      n = head nk
      k = last nk
      rate = drop (n - k) . sort . map (read :: String -> Double) . words . last $ input
  putStrLn . show $ foldl (\x y -> (x + y) / 2) 0 rate
