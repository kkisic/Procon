import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  a <- group . sort <$> getIntListBC
  let num = if even n then [1+(i*2) | i <- [0..(div n 2)-1]]
                      else [i*2 | i <- [0..(div n 2)]]
      rep = map head a
      count = map length a
  if num == rep && check count (even n)
    then print $ power $ div n 2
    else print 0

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

check :: [Int] -> Bool -> Bool
check num b
  | b == True = and $ map (==2) num
  | otherwise = (head num) == 1 && (and $ map (==2) $ tail num)

power :: Int -> Int
power 0 = 1
power n = flip mod (10^9+7) . (*2) $ power (n-1)
