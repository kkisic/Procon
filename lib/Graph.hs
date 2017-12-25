import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Data.Array.Unboxed
import Control.Monad

main :: IO ()
main = return ()

type Memo2D = IOUArray (Int, Int) Int

--let index = [(k, i, j) | k <- [1..n], i <- [1..n], j <- [1..n]]
--(i, i) 0<=i<=n を0で初期化
initWF :: Memo2D -> (Int, Int, Int) -> IO Memo2D
initWF memo (x, y, d) = do
  writeArray memo (x, y) d
  writeArray memo (y, x) d
  return memo

--INFの値に注意
warshallFloyd :: Memo2D -> (Int, Int, Int) -> IO Memo2D
warshallFloyd memo (k, i, j) = do
  x <- readArray memo (i, j)
  y <- readArray memo (i, k)
  z <- readArray memo (k, j)
  let minWeight = min x $ y + z
  writeArray memo (i, j) minWeight
  return memo



type Memo = IOUArray Int Int
type Edge = (Int, Int, Int)
infinite = maxBound :: Int

--始点:s weight[s] = 0, 他はweight[i] = infinite
bellmanFord :: [Edge] -> Int -> Int -> Memo -> Int -> IO Memo
bellmanFord edge n dst weight i = do
  b <- readArray weight 0
  case b of
    0 -> do
      foldM (bf' n dst i) weight edge
      return weight
    _ -> do
      return weight

--始点からdstの間にある負閉路を検出(weight[0] = 1)
bf' :: Int -> Int -> Int -> Memo -> Edge -> IO Memo
bf' n dst i weight (from, to, w) = do
  updatable <- readArray weight 0
  case updatable of
    0 -> do
      distFrom <- readArray weight from
      distTo <- readArray weight to
      let isUpdate = distFrom /= infinite && distTo > distFrom + w
          newDist = if isUpdate then distFrom + w
                                else distTo
          isClosed = if isUpdate && i == n && to == dst
                       then 1 else 0
      writeArray weight to newDist
      writeArray weight 0 isClosed
      return weight
    _ -> do
      return weight



type Weight = Int
type Vertex = (Int, Weight)
--key:頂点番号, value:隣接点集合
type Graph = M.IntMap Neighbor
--key:ある点の隣接点の頂点番号, value:辺の重さ
type Neighbor = M.IntMap Weight

--隣接リスト
makeGraph :: Graph -> (Int, Int, Int) -> Graph
makeGraph graph (x, y, z) =
  let nX = M.lookup x graph
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
      wSum <- readArray weight pre
      writeArray weight i (wSum + w)
      let ne = M.toList . fromJust $ M.lookup i graph
      return =<< foldM (search graph weight i) mark ne

--MST
greedy :: IOUArray Int Int -> [(Int, Int, Int)] -> Int -> Int -> IO Int
greedy parent ((i, j, w):es) n k
  | n == k    = return 0
  | otherwise = do
    pI <- getParent parent i
    pJ <- getParent parent j
    if pI == pJ then greedy parent es n k
                else do
                  writeArray parent pI pJ
                  sum <- greedy parent es n $ k + 1
                  return $ w + sum

getParent :: IOUArray Int Int -> Int -> IO Int
getParent memo i = do
  parent <- readArray memo i
  case parent of
    0 -> return i
    _ -> do
      pp <- getParent memo parent
      writeArray memo i pp
      return pp
