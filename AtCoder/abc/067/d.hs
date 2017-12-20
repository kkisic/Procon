import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Weight = Int
type Vertex = (Int, Weight)
type Graph = M.IntMap Neighbor
type Neighbor = M.IntMap Weight

main = do
  n <- readLn :: IO Int
  edge <- (\[x, y] -> zip x y) . transpose <$> getInt2DListBC
  fennec <- newArray (1, n) 0 :: IO (IOUArray Int Int)
  snuke <- newArray (1, n) 0 :: IO (IOUArray Int Int)
  fMark <- newArray (1, n) False :: IO (IOUArray Int Bool)
  sMark <- newArray (1, n) False :: IO (IOUArray Int Bool)
  let graph = foldl makeGraph M.empty edge
      fNeighbors = M.toList . fromJust $ M.lookup 1 graph
      sNeighbors = M.toList . fromJust $ M.lookup n graph
  writeArray fMark 1 True
  writeArray sMark n True
  foldM (search graph fennec 1) fMark fNeighbors
  foldM (search graph snuke n) sMark sNeighbors
  [x, y] <- group . sort <$> mapM (game fennec snuke) [1..n]
  if length x > length y then putStrLn "Fennec"
                         else putStrLn "Snuke"

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

game :: IOUArray Int Int -> IOUArray Int Int -> Int -> IO Int
game fennec snuke i = do
  f <- readArray fennec i
  s <- readArray snuke i
  return $ if f <= s then 0 else 1

--隣接リスト
makeGraph :: Graph -> (Int, Int) -> Graph
makeGraph graph (x, y) = let nX = M.lookup x graph
                             nY = M.lookup y graph
                             vX = if nX == Nothing
                                    then M.insert x (addNeighbor (y, 1) M.empty) graph
                                    else M.insert x (addNeighbor (y, 1) $ fromJust nX) graph
                         in if nY == Nothing
                              then M.insert y (addNeighbor (x, 1) M.empty) vX
                              else M.insert y (addNeighbor (x, 1) $ fromJust nY) vX

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
