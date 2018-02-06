import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  [n,x] <- map read . words <$> getLine :: IO [Int]
  a <- getIntListBC
  print $ min (solve a x x) (solve (reverse a) x x)


bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

solve :: [Int] -> Int -> Int -> Int
solve [] _ _ = 0
solve (a:as) x r = if r >= a then solve as x $ x - a
                             else (+(a - r)) . solve as x $ x - r
