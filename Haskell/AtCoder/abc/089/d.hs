import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Arr = IOUArray Int Int

main = do
  [h,w,d] <- map read . words <$> getLine :: IO [Int]
  a <- concat <$> replicateM h getIntListBC :: IO [Int]
  let m = foldl' register M.empty $ zip a [(i, j) | i <- [1..h], j <- [1..w]]
  arr <- newArray (1, h*w) 0 :: IO Arr
  foldM (solve m d) arr [d+1..h*w]
  q <- readLn :: IO Int
  replicateM q (query arr)
  return ()

register :: M.IntMap (Int, Int) -> (Int, (Int, Int)) -> M.IntMap (Int, Int)
register m (k, v) = M.insert k v m

solve :: M.IntMap (Int, Int) -> Int -> Arr -> Int -> IO Arr
solve m d arr i = do
  pre <- readArray arr $ i - d
  let (x, y) = fromJust $ M.lookup i m
      (s, t) = fromJust $ M.lookup (i-d) m
  writeArray arr i $ pre + (abs $ s - x) + (abs $ t - y)
  return arr

query :: Arr -> IO ()
query arr = do
  [l, r] <- map read . words <$> getLine :: IO [Int]
  ll <- readArray arr l
  rr <- readArray arr r
  print $ rr - ll

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
