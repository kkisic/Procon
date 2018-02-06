import Data.List
import Data.Maybe

type Mass = (Double, Double, Double, Double)

main = do
  [a,b,c,d,e,f] <- map read . words <$> getLine :: IO [Double]
  let water = [0..30] :: [Double]
      sugar = [0..100] :: [Double]
      pattern = [(a*100*n, b*100*m, c*l, d*k) | n <- water, m <- water, l <- sugar, k <- sugar, a*100*n + b*100*m + c*l + d*k <= f]
  putStrLn . unwords . map (show . truncate) . (\(x, y, z, w) -> [x+y+z+w, z+w]) $ solve e pattern (0, 0, 0, 0)

mix :: Double -> (Double, Double, Double, Double) -> Double
mix e (a, b, c, d)
  | e / (100 + e) >= (c + d) / (a + b + c + d) = (c + d) / (a + b + c + d)
  | otherwise = -1

solve :: Double -> [Mass] -> Mass -> Mass
solve e [] best = best
solve e (m:ms) best
  | mix e m == e / (100 + e) = m
  | mix e m > mix e best = solve e ms m
  | otherwise = solve e ms best
