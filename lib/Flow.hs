import qualified Data.IntMap as M
import Data.Array.IO
import Data.Maybe (fromJust)
import Data.List
import Control.Monad

type Arr = IOUArray Int Bool
type Edge = (Int, Int)
type Weight = Int
type Vertex = (Int, Weight)
--key:頂点番号, value:隣接点集合
type GraphW = M.IntMap Neighbor
--key:ある点の隣接点の頂点番号, value:辺の重さ
type Neighbor = M.IntMap Weight


--Ford-Fulkerson
inf = 10^8

fordFulkerson :: Int -> (Int, GraphW) -> Int -> IO (Int, GraphW)
fordFulkerson dst (flow, graph) v = do
  used <- newArray (0, dst) False :: IO Arr
  (f, g) <- dfs used v dst (inf, graph)
  if f == 0
    then return (flow, g)
    else fordFulkerson dst (flow + f, g) v

dfsFF :: Arr -> Int -> Int -> (Int, GraphW) -> IO (Int, GraphW)
dfsFF used v dst (flow, graph)
  | v == dst = return (flow, graph)
  | otherwise = do
    writeArray used v True
    let ne = M.lookup v graph
    if ne /= Nothing
      then do
        dfsFF' used v dst (flow, graph) $ fst . unzip . M.toList $ fromJust ne
      else return (0, graph)

dfsFF' :: Arr -> Int -> Int -> (Int, GraphW) -> [Int] -> IO (Int, GraphW)
dfsFF' _    _ _   (flow, graph) []      = return (0, graph)
dfsFF' used v dst (flow, graph) (to:ts) = do
  isMark <- readArray used to
  let cap = fromJust $ M.lookup to $ fromJust $ M.lookup v graph
  if not isMark && cap > 0
    then do
      (f, g) <- dfsFF used to dst (min flow cap, graph)
      if f > 0
        then do
          let neV = M.adjust (subtract f) to $ fromJust $ M.lookup v graph
              g' = M.insert v neV g
              neTo = M.adjust (+f) v $ fromJust $ M.lookup to g'
              g'' = M.insert to neTo g'
          return (f, g'')
        else dfsFF' used v dst (flow, graph) ts
    else dfsFF' used v dst (flow, graph) ts


--重み付き隣接リスト
makeGraphW :: GraphW -> Edge -> GraphW
makeGraphW graph (x, y) =
  let nX = M.lookup x graph
      nY = M.lookup y graph
      vX = if nX == Nothing
             then M.insert x (addNeighbor (y, 1) M.empty) graph
             else M.insert x (addNeighbor (y, 1) $ fromJust nX) graph
  in if nY == Nothing
       then M.insert y (addNeighbor (x, 1) M.empty) vX
       else M.insert y (addNeighbor (x, 1) $ fromJust nY) vX

addNeighbor :: Vertex -> Neighbor -> Neighbor
addNeighbor (i, weight) ne = M.insert i weight ne
