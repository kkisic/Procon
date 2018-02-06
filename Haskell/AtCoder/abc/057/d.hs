import Data.List
import GHC.Float
import Text.Printf

main = do
  nab <- map (read :: String -> Int) . words <$> getLine
  v <- reverse . sort . map (read :: String -> Double) . words <$> getLine
  let a = toInteger $ nab !! 1
      b = toInteger $ nab !! 2
      vv = take (nab !! 1) v
      ave = average vv
      lastV = last vv
      selected = length . elemIndices lastV $ vv
      all = toInteger . length . elemIndices lastV $ v
  putStrLn $ printf "%.6f" ave
  if head v == lastV then putStrLn . show . foldl1 (+) . map (conb all) $ [a..b]
                  else putStrLn . show $ conb all (toInteger selected)

average :: [Double] -> Double
average xs = (sum $ map (flip (/) (int2Double $ length xs)) xs)

conb :: Integer -> Integer -> Integer
conb n k = f n k `div` f k k
        where f n k = foldr1 (*) [n-k+1..n]
