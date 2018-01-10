import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type EdgeW = (Int, Int, Int)
type Weight = Int
type Vertex = (Int, Weight)
type GraphW = M.IntMap Neighbor
type Neighbor = M.IntMap Weight
type Cost = IOUArray Int Int
type Node = (Int, Int)

inf = maxBound :: Int

main = do
  [n,m,t] <- map read . words <$> getLine :: IO [Int]
  a <- getIntListBC
  input <- map (\[x,y,w] -> (x,y,w)) <$> getInt2DListBC
  cost <- newArray (1, n) inf :: IO Cost
  costR <- newArray (1, n) inf :: IO Cost
  let graph  = foldl makeGraphW M.empty input
      graphR = foldl makeGraphW M.empty $ map reverseEdge input
      ne  = M.lookup 1 graph
      neR = M.lookup 1 graphR
  if ne == Nothing || neR == Nothing
    then print $ (head a) * t
    else do
      let pq = insertPQ 0 Empty ne
          pqR = insertPQ 0 Empty neR
      writeArray cost 1 0
      dijkstra graph pq cost $ pop pq
      dijkstra graphR pqR costR $ pop pqR
      ans <- mapM (solve cost costR t) (zip [1..n] a)
      print $ maximum ans

solve :: Cost -> Cost -> Int -> (Int, Int) -> IO Int
solve cost costR t (1, a) = do
  return $ a * t
solve cost costR t (i, a) = do
  x <- readArray cost i
  y <- readArray costR i
  if x == inf || y == inf
    then return 0
    else do
      let remain = if t - x - y >= 0 then t - x - y else 0
      return $ remain * a

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

--重み付き有向グラフ隣接リスト
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

reverseEdge :: EdgeW -> EdgeW
reverseEdge (i, j, w) = (j, i, w)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
