import Data.List

main = do
  [n, m, a, b] <- map read . words <$> getLine :: IO [Int]
  x <- sort . map read . words <$> getLine :: IO [Int]
  y <- sort . map read . words <$> getLine :: IO [Int]
  if maximum (a:x) < minimum (b:y)
    then putStrLn "No War"
    else putStrLn "War"
