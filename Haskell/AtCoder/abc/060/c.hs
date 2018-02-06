import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

main = do
  [n, t] <- map read . words <$> getLine :: IO [Int]
  input <- getIntListBC
  print $ solve t input

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

solve :: Int -> [Int] -> Int
solve t (_:[])   = t
solve t (x:y:ys) = if y > x + t then t + solve t (y:ys)
                                else (y - x) + solve t (y:ys)
