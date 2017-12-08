main = do
  input <- tail . map (read :: String -> Int) . lines <$> getContents
  putStrLn . show . sum . map (solve input) $ input

solve :: [Int] -> Int -> Double
solve ls n = let divisor = (flip (-) 1) . length . filter (\x -> mod n x == 0) $ ls
                 divisorDouble = realToFrac divisor
              in if odd divisor
                  then 0.5
                  else (divisorDouble + 2.0) / (divisorDouble * 2.0 + 2.0)
