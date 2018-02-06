import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  getLine
  a <- sum . filter (>0) . map (subtract 1 . length) . group . sort <$> getIntListBC
  print a

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents
