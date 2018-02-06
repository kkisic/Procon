import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  let iList = increase a 1 1
      ans = sum $ map count iList
  print ans

increase :: [Int] -> Int -> Int -> [(Int, Int)]
increase (_:[])   n i = [(i, n)]
increase (x:y:ys) n i
  | x < y     = increase (y:ys) (n+1) i
  | otherwise = (i, n) : (increase (y:ys) (n+1) (n+1))

count :: (Int, Int) -> Int
count (i, j) = sum [1..j-i+1]

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
