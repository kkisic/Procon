import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  [n,h] <- map read . words <$> getLine :: IO [Integer]
  [a, b] <- transpose <$> getInt2DListBC
  let aMax = maximum a
      b' = filter (> aMax) b
      bSum = sum b'
      bSorted = reverse $ sort b'
      remain = h - bSum
      count = if mod remain aMax == 0
                then div remain aMax
                else (+1) $ div remain aMax
  if bSum > h
    then print $ solve h bSorted
    else print $ (length b') + (fromInteger count)

solve :: Integer -> [Integer] -> Integer
solve h [] = 0
solve h (b:bs)
  | h > 0 = 1 + (solve (h-b) bs)
  | otherwise = 0

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Integer]]
getInt2DListBC = map (map (toInteger . bsToInt) . BC.words) . BC.lines <$> BC.getContents
