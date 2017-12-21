import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  [n,a,b] <- map read . words <$> getLine :: IO [Int]
  h <- sort <$> getIntListBC
  print $ lowerBound h a b

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents

lowerBound :: [Int] -> Int -> Int -> Int
lowerBound h a b = innerLB (0-1) (maximum h)
  where innerLB lb ub
          | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                          in if explode h a b mid
                               then innerLB lb mid
                               else innerLB mid ub
          | otherwise   = ub

explode :: [Int] -> Int -> Int -> Int -> Bool
explode h a b k = let add = a - b
                      count = sum . map (divCount add) . filter (>0) $ map (flip (-) (b*k)) h
                  in count <= k

divCount :: Int -> Int -> Int
divCount x n = if mod n x == 0 then div n x
                               else (+1) $ div n x
