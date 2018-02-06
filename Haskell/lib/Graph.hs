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
type Arr2D = IOUArray (Int, Int) Int

--let index = [(k, i, j) | k <- [1..n], i <- [1..n], j <- [1..n]]
--let index = [(k, i, j) | k <- [1..n], i <- [1..n], j <- [i..n]] --無向グラフ時半分推奨
--(i, i) 0<=i<=n を0で初期化
initWF :: Arr2D -> EdgeW -> IO Arr2D
initWF memo (x, y, d) = do
  writeArray memo (x, y) d
  writeArray memo (y, x) d
  return memo

--INFの値に注意
warshallFloyd :: Arr2D -> (Int, Int, Int) -> IO Arr2D
warshallFloyd memo (k, i, j) = do
  x <- readArray memo (i, j)
  y <- readArray memo (i, k)
  z <- readArray memo (k, j)
  let minWeight = min x $ y + z
  writeArray memo (i, j) minWeight
  --writeArray memo (j, i) minWeight 半分時
  return memo



--type EdgeW = (Int, Int, Int)
type Arr = IOUArray Int Int
infinite = maxBound :: Int

--始点:s weight[s] = 0, 他はweight[i] = infinite
bellmanFord :: [EdgeW] -> Int -> Int -> Arr -> Int -> IO Arr
bellmanFord edge n dst weight i = do
  b <- readArray weight 0
  case b of
    0 -> do
      foldM (bf' n dst i) weight edge
      return weight
    _ -> do
      return weight

--始点からdstの間にある負閉路を検出(weight[0] = 1)
bf' :: Int -> Int -> Int -> Arr -> EdgeW -> IO Arr
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



--Dijkstra
type Cost = IOUArray Int Int
type Node = (Int, Int)

inf = 10^10

--dijkstra SkewHeap (dist, vertex), Cost:iへの最短距離
--let pq = insertPQ 0 Empty ne
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

readWeight :: Arr -> Int -> (Int, Int) -> IO Int
readWeight weight k (x, y) = do
  kx <- readArray weight x
  ky <- readArray weight y
  return $ kx + ky


--DFS : 前pre 現在i
dfs :: GraphW -> Arr -> Int -> IOUArray Int Bool -> Vertex -> IO (IOUArray Int Bool)
dfs graph weight pre mark (i, w) = do
  isMark <- readArray mark i
  case isMark of
    True -> do
      return mark
    False -> do
      writeArray mark i True
      wSum <- readArray weight pre
      writeArray weight i (wSum + w)
      let ne = M.toList . fromJust $ M.lookup i graph
      return =<< foldM (dfs graph weight i) mark ne

--MST
greedy :: Arr -> [EdgeW] -> Int -> Int -> IO Int
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

unionFind :: Arr -> [Edge] -> IO Arr
unionFind memo [] = return memo
unionFind memo ((i, j):es) = do
  pI <- getRepresentative memo i
  pJ <- getRepresentative memo j
  if pI == pJ then unionFind memo es
              else do
                writeArray memo pI pJ
                unionFind memo es

getRepresentative :: Arr -> Int -> IO Int
getRepresentative memo i = do
  parent <- readArray memo i
  case parent of
    0 -> return i
    _ -> do
      pp <- getRepresentative memo parent
      writeArray memo i pp
      return pp


--LCA doubling
type Arr = IOUArray Int Int
type Arr2D = IOUArray (Int, Int) Int

--logの上限に注意
maxLog = 18

queryLCA :: Arr -> Arr2D -> Edge -> IO Int
queryLCA depth table (u, v) = do
  a <- lca depth table u v
  d <- readArray depth a
  x <- readArray depth u
  y <- readArray depth v
  return $ (x - d) + (y - d) + 1

--DFS : 前pre 現在v 深さd
dfsLCA :: Graph -> Int -> Int -> Arr2D -> Arr -> Int -> IO Arr
dfsLCA graph pre d table depth v = do
  writeArray table (v, 0) pre
  writeArray depth v d
  let ne = filter (/=pre) . fromJust . M.lookup v $ graph
  if ne /= []
    then foldM (dfsLCA graph v (d+1) table) depth ne
    else return depth

--ダブリング用parent表
makeTableLCA :: Int -> Arr2D -> Int -> IO Arr2D
makeTableLCA n table k = do
  foldM make table [1..n]
  where make :: Arr2D -> Int -> IO Arr2D
        make t v = do
          p <- readArray t (v, k)
          if p == 1
            then return t
            else do
              pp <- readArray t (p, k)
              writeArray t (v, k+1) pp
              return t

--頂点vから根方向にdepth回辿った親
ancestor :: Arr2D -> Int -> Int -> IO Int
ancestor table v depth =
  foldM anc v [0..maxLog-1]
  where anc :: Int -> Int -> IO Int
        anc vv i =
          if shiftR depth i .&. 1 == 1
            then readArray table (vv, i)
            else return vv

lca :: Arr -> Arr2D -> Int -> Int -> IO Int
lca depth table u v = do
  ud <- readArray depth u
  vd <- readArray depth v
  if ud > vd
    then lca depth table v u
    else do
      v' <- ancestor table v (vd - ud)
      if u == v'
        then return u
        else do
          k <- lowerBound (judge table u v') (-1) $ 10^5
          ancestor table u k

judge :: Arr2D -> Int -> Int -> Int -> IO Bool
judge table u v i = do
  up <- ancestor table u i
  vp <- ancestor table v i
  return $ up == vp

lowerBound :: (Int -> IO Bool) -> Int -> Int -> IO Int
lowerBound f lb ub
  | ub - lb == 1 = return ub
  | otherwise = do
    let mid = div (lb + ub) 2
    flag <- f mid
    if flag
      then lowerBound f lb mid
      else lowerBound f mid ub



--bitDP v <- [0..n-1]
dp :: Graph -> Arr -> (Int, Int) -> IO Arr
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
