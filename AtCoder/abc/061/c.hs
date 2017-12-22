import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Control.Monad

main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  input <- sortBy (\x y -> compare (fst x) (fst y)) . (\[x, y] -> zip x y) . transpose <$> getInt2DListBC
  print $ solve k 0 input

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

solve :: Int -> Int -> [(Int, Int)] ->  Int
solve k sum ((a, b):s)
  | sum + b >= k = a
  | otherwise    = solve k (sum + b) s
