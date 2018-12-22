import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import qualified Data.IntMap as M
import Data.Maybe (fromJust)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

main = do
  n <- getLine
  a <- filter odd . concat <$> getInt2DListBC :: IO [Int]
  if a == []
    then putStrLn "second"
    else putStrLn "first"
