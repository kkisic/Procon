import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  [n,a,b] <- map read . words <$> getLine :: IO [Int]
  city <- getIntListBC
  print $ solve city a b

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

solve :: [Int] -> Int -> Int -> Int
solve (_:[])   _ _ = 0
solve (c:d:ds) a b
  | (d-c) * a > b = b + solve (d:ds) a b
  | otherwise     = (d-c) * a + solve (d:ds) a b
