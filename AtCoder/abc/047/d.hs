import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  [n, t] <- map read . words <$> getLine :: IO [Int]
  (a:as) <- getIntListBC
  let diff = solve as a a
      ans = reverse . group . sort $ diff
  print $ length $ head ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

solve :: [Int] -> Int -> Int -> [Int]
solve []     _   _   = []
solve (x:xs) min max
  | x <= min = solve xs x x
  | x >= max = (x - min) : (solve xs min x)
  | otherwise = solve xs min max
