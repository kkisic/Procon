import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  [n, t] <- map read . words <$> getLine :: IO [Int]
  a <- getIntListBC
  print $ solve a t 0 0

solve :: [Int] -> Int -> Int -> Int -> Int
solve []     _ total _     = total
solve (a:as) t total close
  | a <= close = solve as t (total + (a+t-close)) $ a + t
  | otherwise  = solve as t (total + t) $ a + t

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents
