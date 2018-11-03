import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

modM = 10^9+7

main = do
  n <- getLine
  a <- getIntListBC
  print $ solve a 0

solve :: [Int] -> Int -> Int
solve [] a = a
solve (x:xs) a = let b = flip mod modM . (+) x . flip mod modM . (*) (10 ^ (len x)) $ a
                   in solve xs b

len :: Int -> Int
len 0 = 0
len x = 1 + (len $ div x 10)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
