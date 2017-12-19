import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO

main = do
  [n, m] <- map read . words <$> getLine :: IO [Int]
  edge <- (\[x, y] -> zip x y) . transpose <$> getInt2DListBC
  let graph = foldl makeGraph M.empty edge
      neighbor = fromJust $ M.lookup 1 graph
      neighbors = sort . concat $ map (\x -> fromJust $ M.lookup x graph) neighbor
  if n == last neighbors then putStrLn "POSSIBLE"
                         else putStrLn "IMPOSSIBLE"

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

type Graph = M.IntMap [Int]

--隣接リスト
makeGraph :: Graph -> (Int, Int) -> Graph
makeGraph graph (x, y) =
  let nX = M.lookup x graph
      nY = M.lookup y graph
      vX = if nX == Nothing
             then M.insert x [y] graph
             else M.insert x ((:) y $ fromJust nX) graph
  in if nY == Nothing
        then M.insert y [y] vX
        else M.insert y ((:) x $ fromJust nY) vX
