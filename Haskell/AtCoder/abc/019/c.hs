import qualified Data.ByteString.Char8 as BC
import qualified Data.Set as S
import Data.Maybe (fromJust)
import Data.List
import Control.Monad

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  print $ length . S.toList . S.fromList. sort $ map div2 a

div2 :: Int -> Int
div2 n
  | mod n 2 == 0 = div2 $ div n 2
  | otherwise    = n

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
