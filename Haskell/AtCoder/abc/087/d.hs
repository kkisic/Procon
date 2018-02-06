import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  info <- sort . map (\[x,y,z] -> (x,y,z)) <$> getInt2DListBC
  weight <- newArray (1, n) 0 :: IO Arr
  mark <- newArray (1, n) False :: IO Used
  let graph = foldl makeGraphW M.empty info
  ans <- foldM (solve graph weight mark) True [1..n]
  if ans
    then putStrLn "Yes"
    else putStrLn "No"

type Arr = IOUArray Int Int
type Used = IOUArray Int Bool

type EdgeW = (Int, Int, Int)
type Weight = Int
type Vertex = (Int, Weight)
--key:頂点番号, value:隣接点集合
type GraphW = M.IntMap Neighbor
--key:ある点の隣接点の頂点番号, value:辺の重さ
type Neighbor = M.IntMap Weight

solve :: GraphW -> Arr -> Used -> Bool -> Int -> IO Bool
solve graph weight mark ans i = do
  flag <- readArray mark i
  let ne = M.lookup i graph
  if flag || ne == Nothing
    then return ans
    else do
      writeArray mark i True
      ans' <- foldM (dfs graph weight i mark) ans $ M.toList . fromJust $ ne
      return $ ans && ans'

--DFS : 前pre 現在i
dfs :: GraphW -> Arr -> Int -> Used -> Bool -> Vertex -> IO Bool
dfs graph weight pre mark ans (i, w) = do
  isMark <- readArray mark i
  case isMark of
    True -> do
      wi <- readArray weight i
      wp <- readArray weight pre
      return $ ans && wp + w == wi
    False -> do
      writeArray mark i True
      wSum <- readArray weight pre
      writeArray weight i (wSum + w)
      let ne = M.toList . fromJust $ M.lookup i graph
      return =<< foldM (dfs graph weight i mark) ans ne

--重み付き隣接リスト
makeGraphW :: GraphW -> EdgeW -> GraphW
makeGraphW graph (x, y, w) =
  let nX = M.lookup x graph
      nY = M.lookup y graph
      vX = if nX == Nothing
             then M.insert x (addNeighbor (y, w) M.empty) graph
             else M.insert x (addNeighbor (y, w) $ fromJust nX) graph
  in if nY == Nothing
       then M.insert y (addNeighbor (x, negate w) M.empty) vX
       else M.insert y (addNeighbor (x, negate w) $ fromJust nY) vX

addNeighbor :: Vertex -> Neighbor -> Neighbor
addNeighbor (i, weight) ne = M.insert i weight ne

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
