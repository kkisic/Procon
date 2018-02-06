import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  s <- map (map bsToInt . BC.split '*') . BC.split '+' <$> BC.getLine
  let num = length $ filter (notElem 0) s
  print num

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt
