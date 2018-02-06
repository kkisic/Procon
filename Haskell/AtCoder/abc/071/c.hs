import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  getLine
  input <- reverse . concat . filter ((> 1) . length) . group . sort <$> getIntListBC
  if length input < 4 then print 0
                      else let (x:y:z:w:ws) = input
                               a = if z == w then z else w
                           in print $ x * a

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
