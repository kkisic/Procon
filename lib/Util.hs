import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

main :: IO ()
main = return ()

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

--2進数へ基数変換
int2bin :: Int -> [Int]
int2bin 0 = []
int2bin n = n `mod` 2 : int2bin (n `div` 2)


repeatMemo :: IOUArray Int Int -> [Int] -> IO (IOUArray Int Int)
repeatMemo memo (a:b:_) = do
  return =<< foldM memoize memo [a..b]

memoize :: IOUArray Int Int -> Int -> IO (IOUArray Int Int)
memoize memo x = do
  n <- readArray memo x
  writeArray memo x (n+1)
  return memo

repeatMemoize :: IOUArray Int Int -> (Int, Int) -> IO (IOUArray Int Int)
repeatMemoize memo (i, j) = do
  return =<< foldM memoize memo [i..j]


--素数表 pn:登録済の素数の個数 n:表の上限 x:判定対象のリスト
--ex) prime table 1 n [i | i <- [3..n], odd i == True]
prime :: Table -> Int -> Int -> [Int] -> IO Table
prime table pn n []     = return table
prime table pn n x@(i:is) = do
  if i^2 <= n
    then do
      writeArray table (pn+1) i
      let is' = filter ((/=0) . flip mod i) is
      prime table (pn+1) n is'
    else do
      let len = length x
          idx = [pn+1..pn+len]
      prime' $ zip idx x
      return table
            where prime' :: [(Int, Int)] -> IO Table
                  prime' [] = return table
                  prime' ((i, n):ss) = do
                    writeArray table i n
                    prime' ss


--逆元表
type Table = IOUArray Int Int

modN :: Int
modN = 10^9+7

--x^n (mod modN)
(|^) :: Int -> Int -> Int
(|^) x n
  | n == 0    = 1
  | even n    = (mod (x * x) modN) |^ (n `div` 2)
  | otherwise = (flip mod modN) . (*x) $ x |^ (n - 1)

--x! (mod modN)
fact :: Int -> Int
fact n
  | n == 0    = 1
  | otherwise = (flip mod modN) . (*n) $ fact (n-1)

--nCk cn:n!
comb :: Table -> Int -> Int -> Int -> IO Int
comb memo cn n k
  |n >= k = do
    ik <- readArray memo k
    ink <- readArray memo $ n - k
    let tmp = flip mod modN $ cn * ik
        ans = flip mod modN $ tmp * ink
    return ans
  | otherwise = return 0

makeTable :: Table -> Int -> Int -> IO Table
makeTable table n (-1) = return table
makeTable table n i
  | n == i = do
    writeArray table i $ (fact n) |^ (10^9+5)
    makeTable table i $ i-1
  | otherwise = do
    ie <- readArray table (i+1)
    writeArray table i $ flip mod modN $ ie * (i+1)
    makeTable table i $ i-1


--Skew Heap : for Priority-Queue
data SkewHeap a = Empty | Node a (SkewHeap a) (SkewHeap a) deriving (Show, Read, Eq)

merge :: Ord a => SkewHeap a -> SkewHeap a -> SkewHeap a
merge Empty h = h
merge h Empty = h
merge h1@(Node x1 l1 r1) h2@(Node x2 l2 r2)
  | x1 <= x2  = Node x1 (merge h2 r1) l1
  | otherwise = Node x2 (merge h1 r2) l2

singleton :: Ord a => a -> SkewHeap a
singleton x = Node x Empty Empty

push :: Ord a => a -> SkewHeap a -> SkewHeap a
push x heap = merge (singleton x) heap

pop :: Ord a => SkewHeap a -> Maybe a
pop Empty = Nothing
pop (Node x l r) = Just x

deleteMin :: Ord a => SkewHeap a -> SkewHeap a
deleteMin Empty = Empty
deleteMin (Node _ l r) = merge l r
