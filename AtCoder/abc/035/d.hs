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
type Mark = IOUArray Int Bool

inf = maxBound :: Int

main = do
  [n,m,t] <- map read . words <$> getLine :: IO [Int]
  a <- getIntListBC
  input <- map (\[x,y,w] -> (x,y,w)) <$> getInt2DListBC
  cost <- newArray (1, n) inf :: IO Cost
  fix <- newArray (1, n) False :: IO Mark
  costR <- newArray (1, n) inf :: IO Cost
  fixR <- newArray (1, n) False :: IO Mark
  let graph  = foldl makeGraphW M.empty input
      graphR = foldl makeGraphW M.empty $ map reverseEdge input
      ne  = M.lookup 1 graph
      neR = M.lookup 1 graphR
  if ne == Nothing || neR == Nothing
    then print $ (head a) * t
    else do
      let pq  = foldl (addPQ 0) Empty $ M.toList . fromJust $ ne
          pqR = foldl (addPQ 0) Empty $ M.toList . fromJust $ neR
      writeArray cost 1 0
      writeArray fix 1 True
      dijkstra n 1 graph pq fix cost
      dijkstra n 1 graphR pqR fixR costR
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

dijkstra :: Int -> Int -> GraphW -> SkewHeap (Int, Int) -> Mark -> Cost -> IO Cost
dijkstra n num graph pq fix cost
  | n == num = return cost
  | otherwise = do
    let node = pop pq
    if node == Nothing
      then return cost
      else do
        let (w, v) = fromJust node
            pq' = deleteMin pq
        b <- readArray fix v
        if b
          then dijkstra n num graph pq' fix cost
          else do
            writeArray cost v w
            writeArray fix v True
            let ne = M.lookup v graph
            if ne == Nothing
              then dijkstra n (num+1) graph pq' fix cost
              else do
                let pq'' = foldl (addPQ w) pq' $ M.toList . fromJust $ ne
                dijkstra n (num+1) graph pq'' fix cost

addPQ :: Int -> SkewHeap (Int, Int) -> (Int, Int) -> SkewHeap (Int, Int)
addPQ w heap (v', w') = push (w'+w, v') heap

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
