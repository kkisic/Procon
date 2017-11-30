import Control.Monad
import Control.Applicative
import Data.List

main = do
  input <- getContents
  let points = map (read :: String -> Double) . words $ input
  putStrLn $ show . solve . move $ points

move :: [Double] -> [Double]
move x = 0:0:[(x!!2) - (x!!0), (x!!3) - (x!!1), (x!!4) - (x!!0), (x!!5) - (x!!1)]

solve :: [Double] -> Double
solve x = (flip (/)) 2.0 . abs $ (x!!2) * (x!!5) - (x!!3) * (x!!4)
