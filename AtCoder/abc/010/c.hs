main = do
  input <- map (map (read :: String -> Double) . words) . lines <$> getContents
  let start = (flip (!!) 0 $ head input, flip (!!) 1 $ head input)
      end   = (flip (!!) 2 $ head input, flip (!!) 3 $ head input)
      t     = flip (!!) 4 . head $ input
      v     = flip (!!) 5 . head $ input
      girls = drop 2 $ input
  if or . map (solve start end (t*v)) $ girls
    then putStrLn "YES"
    else putStrLn "NO"

solve :: (Double, Double) -> (Double, Double) -> Double -> [Double] -> Bool
solve (sx, sy) (ex, ey) d [] = False
solve (sx, sy) (ex, ey) d (x:y:s) =
  sqrt ((x - sx) ^ 2 + (y - sy) ^ 2) + sqrt ((ex - x) ^ 2 + (ey - y) ^ 2) <= d
solve (sx, sy) (ex, ey) d _ = False
