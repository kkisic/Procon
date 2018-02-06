import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import Data.Maybe (fromJust)
import Data.List

main = do
  [n,k] <- map read . words <$> getLine :: IO [Int]
  s <- getIntListBC
  if elem 0 s
    then print n
    else if (length $ filter (<=k) s) == 0
           then print 0
           else print $ maximum $ solve k 1 0 S.empty s

solve :: Int -> Int -> Int -> S.Seq Int -> [Int] -> [Int]
solve _     _   _     _           []     = []
solve limit mul count seq (n:ns)
  | S.length seq == 0 && limit >= mul * n
    = (count+1) : (solve limit (mul*n) (count+1) (S.empty S.|> n) ns)
  | S.length seq == 0 = solve limit mul count S.empty ns
  | limit >= mul * n  = (count+1) : (solve limit (mul*n) (count+1) (seq S.|> n) ns)
  | otherwise         = solve limit (div mul (fst . dequeue $ seq)) (count-1) (S.drop 1 seq) (n:ns)

dequeue :: S.Seq a -> (a, S.Seq a)
dequeue que = case S.viewl que of
                S.EmptyL -> error "Empty Queue"
                x S.:< xs -> (x, xs)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents
