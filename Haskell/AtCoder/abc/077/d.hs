import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

main = do
  k <- readLn :: IO Int
  cost <- newArray (0, k-1) inf :: IO Cost
  let graph = foldl' (make k) M.empty [1..k-1]
      pq = insertPQ 0 Empty $ M.lookup 1 graph
  writeArray cost 1 0
  dijkstra graph pq cost $ pop pq
  ans <- readArray cost 0
  print $ ans + 1

type Cost = IOUArray Int Int
type Node = (Int, Int)

inf = 100

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

type EdgeW = (Int, Int, Int)
type Weight = Int
type Vertex = (Int, Weight)
type GraphW = M.IntMap Neighbor
type Neighbor = M.IntMap Weight

make :: Int -> GraphW -> Int -> GraphW
make k graph i =
  let g = makeGraphW graph (i, mod (i+1) k, 1)
  in makeGraphW g (i, mod (i*10) k, 0)

--重み付き隣接リスト
makeGraphW :: GraphW -> EdgeW -> GraphW
makeGraphW graph (x, y, w) =
  let nX = M.lookup x graph
      nY = M.lookup y graph
  in if nX == Nothing
       then M.insert x (addNeighbor (y, w) M.empty) graph
       else M.insert x (addNeighbor (y, w) $ fromJust nX) graph

addNeighbor :: Vertex -> Neighbor -> Neighbor
addNeighbor (i, weight) ne = M.insert i weight ne

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
