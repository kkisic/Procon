import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Char
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Array = IOUArray Int Int

main = do
  [n,q] <- map read . words <$> getLine :: IO [Int]
  [l,r] <- transpose <$> getInt2DListBC
  ll <- newArray (1, n) 0 :: IO Array
  rr <- newArray (1, n+1) 0 :: IO Array
  ans <- newArray (1, n) 0 :: IO Array
  foldM memo ll (map (\x -> (head x, length x)) . group . sort $ l)
  foldM memo rr (map (\x -> ((+1).head $ x, length x)) . group . sort $ r)
  l' <- getElems ll
  r' <- getElems rr
  putStrLn $ map (intToDigit . flip mod 2) $ count l' r' 0

count :: [Int] -> [Int] -> Int -> [Int]
count []     _      _   = []
count (l:ls) (r:rs) pre = let c = pre + l - r
                          in c : (count ls rs c)

memo :: Array -> (Int, Int) -> IO Array
memo a (i, v) = do
  writeArray a i v
  return a

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
