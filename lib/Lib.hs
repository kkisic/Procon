import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Data.Array.Unboxed
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

--[lb, ub) x未満のmax
upperBound :: Int -> UArray Int Int -> Int
upperBound x xs = innerUB (0-1) ((+1) . snd $ bounds xs) x xs

innerUB :: Int -> Int -> Int -> UArray Int Int -> Int
innerUB lb ub x xs
  | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                   in if (xs ! mid) < x then innerUB mid ub x xs
                                        else innerUB lb mid x xs
  | otherwise   = lb

--(lb, ub] xより大きいmin
lowerBound :: Int -> UArray Int Int -> Int
lowerBound x xs = innerLB (0-1) ((+1) . snd $ bounds xs) x xs

innerLB :: Int -> Int -> Int -> UArray Int Int -> Int
innerLB lb ub x xs
  | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                   in if (xs ! mid) > x then innerLB lb mid x xs
                                        else innerLB mid ub x xs
  | otherwise   = ub

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

type Memo = IOUArray (Int, Int) Int

--let index = [(k, i, j) | k <- [1..n], i <- [1..n], j <- [1..n]]
initWF :: Memo -> (Int, Int, Int) -> IO Memo
initWF memo (x, y, d) = do
  writeArray memo (x, y) d
  writeArray memo (y, x) d
  return memo

--INFの値に注意
warshallFloyd :: Memo -> (Int, Int, Int) -> IO Memo
warshallFloyd memo (k, i, j) = do
  x <- readArray memo (i, j)
  y <- readArray memo (i, k)
  z <- readArray memo (k, j)
  let minWeight = min x $ y + z
  writeArray memo (i, j) minWeight
  return memo

type Weight = Int
type Vertex = (Int, Weight)
--key:頂点番号, value:隣接点集合
type Graph = M.IntMap Neighbor
--key:ある点の隣接点の頂点番号, value:辺の重さ
type Neighbor = M.IntMap Weight

--隣接リスト
makeGraph :: Graph -> (Int, Int, Int) -> Graph
makeGraph graph (x, y, z) = let nX = M.lookup x graph
                                nY = M.lookup y graph
                                vX = if nX == Nothing
                                       then M.insert x (addNeighbor (y, z) M.empty) graph
                                       else M.insert x (addNeighbor (y, z) $ fromJust nX) graph
                            in if nY == Nothing
                                 then M.insert y (addNeighbor (x, z) M.empty) vX
                                 else M.insert y (addNeighbor (x, z) $ fromJust nY) vX

readWeight :: IOUArray Int Int -> Int -> (Int, Int) -> IO Int
readWeight weight k (x, y) = do
  kx <- readArray weight x
  ky <- readArray weight y
  return $ kx + ky

addNeighbor :: (Int, Int) -> Neighbor -> Neighbor
addNeighbor (i, weight) ne = M.insert i weight ne

readEdge :: Graph -> (Int, Int) -> Int
readEdge graph (i, j) = let ne = fromJust $ M.lookup i graph
                        in fromJust $ M.lookup j ne

--DFS : 前pre 現在i
search :: Graph -> IOUArray Int Int -> Int -> IOUArray Int Bool -> Vertex -> IO (IOUArray Int Bool)
search graph weight pre mark (i, w) = do
  isMark <- readArray mark i
  case isMark of
    True -> do
      return mark
    False -> do
      writeArray mark i True
      let ne = M.toList . fromJust $ M.lookup i graph
      wSum <- readArray weight pre
      writeArray weight i (wSum + w)
      return =<< foldM (search graph weight i) mark ne

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

comb :: Table -> Int -> Int -> Int -> IO Int
comb memo cn n k
  |n >= k = do
    ik <- readArray memo k
    ink <- readArray memo $ n - k
    let tmp = flip mod modN $ cn * ik
        ans = flip mod modN $ tmp * ink
    return ans
  | otherwise = return 0
