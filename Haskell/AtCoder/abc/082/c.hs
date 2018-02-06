import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  getLine
  a <- map (\x -> (head x, length x)) . group . sort <$> getIntListBC
  print $ judge a

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

judge :: [(Int, Int)] -> Int
judge [] = 0
judge (x:xs)
  | fst x == snd x = judge xs
  | fst x < snd x  = (snd x - fst x) + judge xs
  | otherwise      = (snd x) + judge xs
