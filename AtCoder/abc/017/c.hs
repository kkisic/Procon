import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import qualified Data.IntMap as M
import Data.Array.IO
import Data.Maybe (fromJust)
import Data.List
import Control.Monad

type Arr = IOUArray Int Int

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  input <- getInt2DListBC
  l <- newArray (1, m+1) 0 :: IO Arr
  r <- newArray (1, m+1) 0 :: IO Arr
  foldM (count l) r input
  ll <- getElems l
  rr <- getElems r
  let ans = init $ solve ll rr 0
      max = foldl sumScore 0 input
  print $ max - (minimum ans)

sumScore :: Int -> [Int] -> Int
sumScore s [_,_,x] = s+x

solve :: [Int] -> [Int] -> Int -> [Int]
solve []     []     _ = []
solve (l:ls) (r:rs) s = (s+l+r) : solve ls rs (s+l+r)

count :: Arr -> Arr -> [Int] -> IO Arr
count la ra [l,r,s] = do
  ll <- readArray la l
  rr <- readArray ra $ r+1
  writeArray la l $ ll + s
  writeArray ra (r+1) $ rr - s
  return ra

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
