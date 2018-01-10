import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Data.Array.Unboxed
import Control.Monad

main :: IO ()
main = return ()

--重み付き辺
type EdgeW = (Int, Int, Int)
type Memo2D = IOUArray (Int, Int) Int

--let index = [(k, i, j) | k <- [1..n], i <- [1..n], j <- [1..n]]
--(i, i) 0<=i<=n を0で初期化
initWF :: Memo2D -> EdgeW -> IO Memo2D
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



--type EdgeW = (Int, Int, Int)
type Memo = IOUArray Int Int
infinite = maxBound :: Int

--始点:s weight[s] = 0, 他はweight[i] = infinite
bellmanFord :: [EdgeW] -> Int -> Int -> Memo -> Int -> IO Memo
bellmanFord edge n dst weight i = do
  b <- readArray weight 0
  case b of
    0 -> do
      foldM (bf' n dst i) weight edge
      return weight
    _ -> do
      return weight

--始点からdstの間にある負閉路を検出(weight[0] = 1)
bf' :: Int -> Int -> Int -> Memo -> EdgeW -> IO Memo
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



type Cost = IOUArray Int Int
type Node = (Int, Int)

--dijkstra SkewHeap (dist, vertex), Cost:iへの最短距離
--let pq = insertPQ 0 Empty ne
--    pqR = insertPQ 0 Empty neR
--writeArray cost 1 0
--dijkstra graph pq cost $ pop pq
dijkstra :: GraphW -> SkewHeap (Int, Int) -> Cost -> Maybe Node -> IO Cost
dijkstra graph pq cost Nothing = return cost
dijkstra graph pq cost node = do
  let (w, v) = fromJust node
      pq' = deleteMin pq
  c <- readArray cost v
  if c /= inf
    then dijkstra graph pq' cost $ pop pq'
    else do
      writeArray cost v w
      let ne = M.lookup v graph
          pq'' = insertPQ w pq ne
      dijkstra graph pq'' cost $ pop pq''

insertPQ :: Int -> SkewHeap (Int, Int) -> Maybe Neighbor -> SkewHeap (Int, Int)
insertPQ w heap Nothing = heap
insertPQ w heap ne      =
  let neList = M.toList . fromJust $ ne
  in foldl add heap neList
  where add heap (v', w') = push (w'+w, v') heap


type Edge = (Int, Int)
type Graph = M.IntMap [Int]

--重み無し隣接リスト
makeGraph :: Graph -> Edge -> Graph
makeGraph graph (x, y) =
  let nX = M.lookup x graph
      nY = M.lookup y graph
      vX = if nX == Nothing
             then M.insert x [y] graph
             else M.insert x (y : (fromJust nX)) graph
  in if nY == Nothing
       then M.insert y [x] vX
       else M.insert y (x : (fromJust nY)) vX


--type EdgeW = (Int, Int, Int)
type Weight = Int
type Vertex = (Int, Weight)
--key:頂点番号, value:隣接点集合
type GraphW = M.IntMap Neighbor
--key:ある点の隣接点の頂点番号, value:辺の重さ
type Neighbor = M.IntMap Weight

--重み付き隣接リスト
makeGraphW :: GraphW -> EdgeW -> GraphW
makeGraphW graph (x, y, w) =
  let nX = M.lookup x graph
      nY = M.lookup y graph
      vX = if nX == Nothing
             then M.insert x (addNeighbor (y, w) M.empty) graph
             else M.insert x (addNeighbor (y, w) $ fromJust nX) graph
  in if nY == Nothing
       then M.insert y (addNeighbor (x, w) M.empty) vX
       else M.insert y (addNeighbor (x, w) $ fromJust nY) vX

addNeighbor :: Vertex -> Neighbor -> Neighbor
addNeighbor (i, weight) ne = M.insert i weight ne

readEdge :: GraphW -> (Int, Int) -> Int
readEdge graph (i, j) = let ne = fromJust $ M.lookup i graph
                        in fromJust $ M.lookup j ne

readWeight :: Memo -> Int -> (Int, Int) -> IO Int
readWeight weight k (x, y) = do
  kx <- readArray weight x
  ky <- readArray weight y
  return $ kx + ky


--DFS : 前pre 現在i
search :: GraphW -> Memo -> Int -> IOUArray Int Bool -> Vertex -> IO (IOUArray Int Bool)
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
greedy :: Memo -> [EdgeW] -> Int -> Int -> IO Int
greedy parent ((i, j, w):es) n k
  | n == k    = return 0
  | otherwise = do
    pI <- getRepresentative parent i
    pJ <- getRepresentative parent j
    if pI == pJ then greedy parent es n k
                else do
                  writeArray parent pI pJ
                  sum <- greedy parent es n $ k + 1
                  return $ w + sum

unionFind :: Memo -> [Edge] -> IO Memo
unionFind memo [] = return memo
unionFind memo ((i, j):es) = do
  pI <- getRepresentative memo i
  pJ <- getRepresentative memo j
  if pI == pJ then unionFind memo es
              else do
                writeArray memo pI pJ
                unionFind memo es

getRepresentative :: Memo -> Int -> IO Int
getRepresentative memo i = do
  parent <- readArray memo i
  case parent of
    0 -> return i
    _ -> do
      pp <- getRepresentative memo parent
      writeArray memo i pp
      return pp



--bitDP v <- [0..n-1]
dp :: Graph -> Memo -> (Int, Int) -> IO Memo
dp graph memo (a, v) = do
  if 1 .&. shiftR a v == 1
    then return memo
    else do
      let sK = M.lookup v graph
          isRight = if sK == Nothing
                    then True
                    else not . contains a $ fromJust sK
      if isRight
        then do
          x <- readArray memo a
          y <- readArray memo $ a .|. shiftL 1 v
          writeArray memo (a .|. shiftL 1 v) $ x + y
          return memo
        else return memo


contains :: Int -> [Int] -> Bool
contains a sk = or $ map ((==1) . (.&.1) . shiftR a) sk
