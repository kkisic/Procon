import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  let s = sum a
  print $ minimum . init $ solve 0 s a

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

solve :: Int -> Int -> [Int] -> [Int]
solve _ _ []     = []
solve i s (a:as) = let t = s - (a + i)
                   in (abs $ t - (a + i)) : solve (a+i) s as
