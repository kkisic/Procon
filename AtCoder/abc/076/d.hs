import Data.List
import Text.Printf

main = do
  getLine
  t <- map (read :: String -> Double) . words <$> getLine
  v <- map (read :: String -> Double) . words <$> getLine
  let table = timeTable 0 t
      end = snd . last $ table
  putStrLn . printf "%.3f" . integral . solve [0, 0.5..end] $ makeConditions end table v

timeTable :: Double -> [Double] -> [(Double, Double)]
timeTable _ [] = []
timeTable n (t:ts) = (n, n+t) : timeTable (n+t) ts

condition :: Double -> (Double, Double) -> Double -> Double -> Double
condition t (l, r) v x
  | 0 <= x && x <= l = v + l - x
  | l <= x && x <= r = v
  | otherwise        = v + x - r

makeConditions :: Double -> [(Double, Double)] -> [Double] -> [Double -> Double]
makeConditions t tt v = (condition t (0, 0) 0) :
                        zipWith (condition t) tt v
                        ++ [condition t (t, t) 0]

solve :: [Double] -> [Double -> Double] -> [Double]
solve time cond = map (\x -> minimum $ map (\f -> f x) cond) time

integral :: [Double] -> Double
integral (_:[]) = 0
integral (x:y:ys) = ((x + y) / 4) + integral (y:ys)
