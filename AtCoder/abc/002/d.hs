import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Bits

main = do
  [n, m] <- map read . words <$> getLine :: IO [Int]
  input <- map ((\[x,y] -> (read x, read y)) . words) . lines <$> getContents :: IO [Edge]
  let graph = foldl makeGraph M.empty input
      pattern = [1..  2^n-1]
  print $ maximum $ map (solve graph) pattern

solve :: Graph -> Int -> Int
solve graph s =
  let pairs = makePair $ bitToSet 1 s
      connected = and $ map (isConnect graph) pairs
  in if connected
       then popCount s
       else 0

isConnect :: Graph -> (Int, Int) -> Bool
isConnect graph (s, t) =
  let ne = M.lookup s graph
  in if ne == Nothing
       then False
       else elem t $ fromJust ne

bitToSet :: Int -> Int -> [Int]
bitToSet i 0 = []
bitToSet i s = if s .&. 1 == 1
                 then i : (bitToSet (i+1) $ shiftR s 1)
                 else bitToSet (i+1) $ shiftR s 1

makePair :: [Int] -> [(Int, Int)]
makePair s = [(i, j) | i <- s, j <- s, i < j]

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
