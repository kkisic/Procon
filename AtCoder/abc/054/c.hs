import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  input <- (\[x,y] -> zip x y) . transpose . map (map read . words) . lines <$> getContents :: IO [(Int, Int)]
  let graph = foldl makeGraph M.empty input
      ne = fromJust $ M.lookup 1 graph
  count <- newArray (0, 0) 0 :: IO (IOUArray Int Int)
  mark <- newArray (1, n) False :: IO (IOUArray Int Bool)
  writeArray mark 1 True
  foldM (search graph count (n-1) 1 1) mark ne
  print =<< head <$> getElems count

--key:頂点番号, value:隣接点集合
type Graph = M.IntMap [Int]

--隣接リスト
makeGraph :: Graph -> (Int, Int) -> Graph
makeGraph graph (x, y) =
  let nX = M.lookup x graph
      nY = M.lookup y graph
      vX = if nX == Nothing
             then M.insert x [y] graph
             else M.insert x (y:(fromJust nX)) graph
  in if nY == Nothing
       then M.insert y [x] vX
       else M.insert y (x:(fromJust nY)) vX

--DFS : 前pre 現在i
search :: Graph -> IOUArray Int Int -> Int -> Int -> Int -> IOUArray Int Bool -> Int -> IO (IOUArray Int Bool)
search graph count n k pre mark i = do
  isMark <- readArray mark i
  case isMark of
    True -> do
      return mark
    False -> do
      c <- readArray count 0
      let c' = if n == k then c+1 else c
      writeArray count 0 c'
      writeArray mark i True
      let ne = fromJust $ M.lookup i graph
      foldM (search graph count n (k+1) i) mark ne
      writeArray mark i False
      return mark
