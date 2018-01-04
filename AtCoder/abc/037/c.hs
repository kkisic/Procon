import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  [n,k] <- map read . words <$> getLine :: IO [Int]
  a <- getIntegerListBC
  let s = cumulativeSum 0 a
      x = drop (k-1) s
      y = 0 : s
  print $ sum $ zipWith (-) x y

cumulativeSum :: Integer -> [Integer] -> [Integer]
cumulativeSum s [] = []
cumulativeSum s (k:ks) = (s+k) : (cumulativeSum (s+k) ks)

bsToInteger :: BC.ByteString -> Integer
bsToInteger = fst . fromJust . BC.readInteger

getIntegerListBC :: IO [Integer]
getIntegerListBC = map bsToInteger . BC.words <$> BC.getLine
