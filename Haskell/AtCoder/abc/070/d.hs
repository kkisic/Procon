import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import qualified Data.IntMap as M
import Control.Monad

type Weight = Int
type Vertex = (Int, Weight)
type Neighbor = M.IntMap Int
type Graph = M.IntMap Neighbor

main = do
  n <- readLn :: IO Int
  edge <- (\[x,y,z] -> zip3 x y z) . transpose <$> replicateM (n-1) getIntListBC
  [q, k] <- map read . words <$> getLine :: IO [Int]
  query <- (\[x,y] -> zip x y) . transpose <$> getInt2DListBC
  mark <- newArray (1, n) False :: IO (IOUArray Int Bool)
  weight <- newArray (1, n) 0 :: IO (IOUArray Int Int)
  let graph = foldl makeGraph (M.empty) edge
      kNeighbors = M.toList . fromJust $ M.lookup k graph
  writeArray mark k True
  foldM (search graph weight k) mark kNeighbors
  ans <- mapM (readWeight weight k) query
  putStr . unlines . map show $ ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

makeGraph :: Graph -> (Int, Int, Int) -> Graph
makeGraph graph (x, y, z) = let nX = M.lookup x graph
                                nY = M.lookup y graph
                                vX = if nX == Nothing
                                       then M.insert x (addNeighbor (y, z) M.empty) graph
                                       else M.insert x (addNeighbor (y, z) $ fromJust nX) graph
                            in if nY == Nothing
                                 then M.insert y (addNeighbor (x, z) M.empty) vX
                                 else M.insert y (addNeighbor (x, z) $ fromJust nY) vX

addNeighbor :: (Int, Int) -> Neighbor -> Neighbor
addNeighbor (i, weight) ne = M.insert i weight ne

readEdge :: Graph -> (Int, Int) -> Int
readEdge graph (i, j) = let ne = fromJust $ M.lookup i graph
                        in fromJust $ M.lookup j ne

--始点k 前pre 現在i
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

readWeight :: IOUArray Int Int -> Int -> (Int, Int) -> IO Int
readWeight weight k (x, y) = do
  kx <- readArray weight x
  ky <- readArray weight y
  return $ kx + ky
