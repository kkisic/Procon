import Data.Array.IO
import Data.List
import Control.Monad
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

type Memo = IOUArray (Int, Int) Int
type Road = IOUArray (Int, Int) Bool

main = do
  n <- readLn :: IO Int
  input <- concat <$> getIntListBC :: IO [Int]
  let index = [(i, j, k) | i <- [1..n], j <- [i+1..n], k <- [1..n], j /= k, k /= i]
  memo <- newListArray ((1, 1), (n, n)) input :: IO Memo
  road <- newArray ((1, 1), (n, n)) True :: IO Road
  memo' <- foldM (memoizeWF road) memo index
  ans <- getElems memo'
  if input /= ans then putStrLn "-1"
                  else do
                    necessary <- getElems road
                    print $ flip div 2 . sum $ zipWith (\x y -> if x then y else 0) necessary ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [[Int]]
getIntListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

memoizeWF :: Road -> Memo -> (Int, Int, Int) -> IO (Memo)
memoizeWF road memo (i, j, k) = do
  let (ii, jj) = if i < j then (i, j) else (j, i)
  b <- readArray road (ii, jj)
  x <- readArray memo (ii, jj)
  y <- readArray memo (ii, k)
  z <- readArray memo (k, jj)
  let minWeight = min x $ y + z
  writeArray road (ii, jj) $ b && x < y + z
  writeArray memo (ii, jj) minWeight
  writeArray road (jj, ii) $ b && x < y + z
  writeArray memo (jj, ii) minWeight
  return memo
