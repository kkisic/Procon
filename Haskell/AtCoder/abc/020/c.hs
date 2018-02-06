import qualified Data.IntMap as M
import Data.Array.IO
import Data.Array.Unboxed
import Data.Maybe (fromJust)
import Data.List

type Arr = UArray Int Char
type EdgeW = (Int, Int, Int)
type Weight = Int
type Vertex = (Int, Weight)
type GraphW = M.IntMap Neighbor
type Neighbor = M.IntMap Weight

inf = 10^10

main = do
  [h,w,t] <- map read . words <$> getLine :: IO [Int]
  s <- lines <$> getContents
  let area = listArray (1, h*w) $ concat s :: Arr
      src = search area 'S' [1..h*w]
      dst = search area 'G' [1..h*w]
      row1 = concat $ zipWith (makeEdgeR 1) [i*w | i <- [0..h-1]] $ map tail s
      row2 = concat $ zipWith (makeEdgeR' 1) [i*w | i <- [0..h-1]] $ s
      column1 = concat $ zipWith (makeEdgeC w 1) [0..w-1] $ map tail $ transpose s
      column2 = concat $ zipWith (makeEdgeC' w 1) [0..w-1] $ transpose s
  let graph = foldl makeGraphW M.empty $ row1 ++ row2 ++ column1 ++ column2
  ans <- upperBound graph (h*w) src dst t
  print ans

--[lb, ub) x未満のmax
upperBound :: GraphW -> Int -> Int -> Int -> Int -> IO Int
upperBound graph n src dst t = innerUB (0-1) t
  where innerUB lb ub
          | ub - lb > 1 = do
            let mid = lb + (ub - lb) `div` 2
            ans <- judge graph n src dst mid
            if ans <= t
              then innerUB mid ub
              else innerUB lb mid
          | otherwise   = return lb

judge :: GraphW -> Int -> Int -> Int -> Int -> IO Int
judge graph n src dst x = do
  cost <- newArray (1, n) inf :: IO Cost
  let pq = insertPQ x 0 Empty $ M.lookup src graph
  writeArray cost src 0
  dijkstra x graph pq cost $ pop pq
  ans <- readArray cost dst
  return ans

type Cost = IOUArray Int Int
type Node = (Int, Int)

dijkstra :: Int -> GraphW -> SkewHeap (Int, Int) -> Cost -> Maybe Node -> IO Cost
dijkstra x graph pq cost Nothing = return cost
dijkstra x graph pq cost node = do
  let (w, v) = fromJust node
      pq' = deleteMin pq
  c <- readArray cost v
  if c /= inf
    then dijkstra x graph pq' cost $ pop pq'
    else do
      writeArray cost v w
      let ne = M.lookup v graph
          pq'' = insertPQ x w pq ne
      dijkstra x graph pq'' cost $ pop pq''

insertPQ :: Int -> Int -> SkewHeap (Int, Int) -> Maybe Neighbor -> SkewHeap (Int, Int)
insertPQ x w heap Nothing = heap
insertPQ x w heap ne      =
  let neList = map (\(v, d) -> if d == 2 then (v, x) else (v, d)) . M.toList . fromJust $ ne
  in foldl add heap neList
  where add heap (v', w') = push (w'+w, v') heap

search :: Arr -> Char -> [Int] -> Int
search arr c []     = negate 1
search arr c (i:is) =
  let x = arr ! i
  in if x == c
       then i
       else search arr c is

makeEdgeR :: Int -> Int -> String -> [EdgeW]
makeEdgeR i bias []       = []
makeEdgeR i bias ('#':ss) = (bias+i, bias+i+1, 2) : (makeEdgeR (i+1) bias ss)
makeEdgeR i bias (_:ss)   = (bias+i, bias+i+1, 1) : (makeEdgeR (i+1) bias ss)

makeEdgeR' :: Int -> Int -> String -> [EdgeW]
makeEdgeR' i bias (_:[])   = []
makeEdgeR' i bias ('#':ss) = (bias+i+1, bias+i, 2) : (makeEdgeR' (i+1) bias ss)
makeEdgeR' i bias (_:ss)   = (bias+i+1, bias+i, 1) : (makeEdgeR' (i+1) bias ss)

makeEdgeC :: Int -> Int -> Int -> String -> [EdgeW]
makeEdgeC w i bias []       = []
makeEdgeC w i bias ('#':ss) = (bias+i, bias+i+w, 2) : (makeEdgeC w (i+w) bias ss)
makeEdgeC w i bias (_:ss)   = (bias+i, bias+i+w, 1) : (makeEdgeC w (i+w) bias ss)

makeEdgeC' :: Int -> Int -> Int -> String -> [EdgeW]
makeEdgeC' w i bias (_:[])   = []
makeEdgeC' w i bias ('#':ss) = (bias+i+w, bias+i, 2) : (makeEdgeC' w (i+w) bias ss)
makeEdgeC' w i bias (_:ss)   = (bias+i+w, bias+i, 1) : (makeEdgeC' w (i+w) bias ss)

--重み付き隣接リスト
makeGraphW :: GraphW -> EdgeW -> GraphW
makeGraphW graph (x, y, w) =
  let nX = M.lookup x graph
  in if nX == Nothing
       then M.insert x (addNeighbor (y, w) M.empty) graph
       else M.insert x (addNeighbor (y, w) $ fromJust nX) graph

addNeighbor :: Vertex -> Neighbor -> Neighbor
addNeighbor (i, weight) ne = M.insert i weight ne

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
