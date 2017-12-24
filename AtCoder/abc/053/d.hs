import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  let a' = sum . map (\x -> (length x) - 1) . group . sort $ a
  if even a' then print $ n - a'
             else print $ n - a' - 1

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
