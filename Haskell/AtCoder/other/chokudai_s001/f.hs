import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- getLine
  a <- getIntListBC
  print $ f a 0

f :: [Int] -> Int -> Int
f [] _     = 0
f (x:xs) m = if x > m
                then 1 + f xs x
                else f xs m

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
