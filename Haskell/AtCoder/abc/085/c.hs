import Data.List
import qualified Data.IntMap as M
import Data.Maybe(fromJust)

main = do
  [n,y] <- map read . words <$> getLine :: IO [Int]
  let patten = [(i, j) | i <- [0..n], j <- [0..n-i]]
      m = foldl (solve n y) M.empty patten
      ans = M.lookup y m
  if ans /= Nothing
    then let (a, b) = fromJust ans
         in putStrLn $ show a ++ " " ++ show b ++ " " ++ show (n-a-b)
    else putStrLn "-1 -1 -1"

solve :: Int -> Int -> M.IntMap (Int, Int) -> (Int, Int) -> M.IntMap (Int, Int)
solve n y m (i, j) = M.insert (i*10000+j*5000+(n-i-j)*1000) (i, j) m
