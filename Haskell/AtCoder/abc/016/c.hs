import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  edge <- map ((\[x,y] -> (read x, read y)) . words) . lines <$> getContents :: IO [Edge]
  let graph = foldl makeGraph M.empty edge
      ans = map (solve graph) [1..n]
  putStr $ unlines . map show $ ans

solve :: Graph -> Int -> Int
solve graph i =
  let ne = M.lookup i graph
  in if ne == Nothing
       then 0
       else let f = fromJust ne
                ff = nub . concat . map (solve' graph) $ f
            in length $ (ff \\ f) \\ [i]

solve' :: Graph -> Int -> [Int]
solve' graph i =
  let ne = M.lookup i graph
  in if ne == Nothing
       then []
       else fromJust ne

type Edge = (Int, Int)
type Graph = M.IntMap [Int]

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
