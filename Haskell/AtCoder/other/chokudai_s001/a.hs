import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- getLine
  a <- getIntListBC
  print $ maximum a

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
