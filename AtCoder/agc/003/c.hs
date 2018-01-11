import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  let b = sort $ zip a [1..n]
      c = sort $ zipWith (\(x, y) z -> abs $ y-z) b [1..n]
  print $ flip div 2 . sum . map (flip mod 2) $ c

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents
