import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Arr = IOUArray Int Int
type ArrB = IOUArray Int Bool
type Edge = (Int, Int)
type Graph = M.IntMap [Int]

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  a <- getIntListBC
  edge <- if m > 0
            then map (\[x,y] -> (x,y)) <$> getInt2DListBC
            else return [] :: IO [(Int, Int)]
  parent <- newArray (-1, n-1) 0 :: IO Arr
  mark <- newArray (1, n) False :: IO ArrB
  let weight = sort $ zip a [0..n-1]
  let graph = foldl' makeGraph M.empty edge
  foldM (solve graph) parent [0..n-1]
  l <- length . group . sort . tail <$> getElems parent
  weight' <- select parent mark l weight
  single <- length . filter (==1) . map length . group . sort . tail <$> getElems parent
  ans1 <- if l > 1 then readArray parent (-1) else return 0
  let ans2 = sum . map fst . take (l-2) $ weight'
  if single > (n - single) - (l - single - 1)*2
    then putStrLn "Impossible"
    else print $ ans1 + ans2

solve :: Graph -> Arr -> Int -> IO Arr
solve graph arr i = dfs graph i arr i

--DFS : 前pre 現在i
dfs :: Graph -> Int -> Arr -> Int -> IO Arr
dfs graph p mark i = do
  n <- readArray mark i
  if n /= 0
    then return mark
    else do
      writeArray mark i $ p+1
      let ne = M.lookup i graph
      if ne /= Nothing
        then return =<< foldM (dfs graph p) mark $ fromJust ne
        else return mark

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

select :: Arr -> ArrB -> Int -> [(Int, Int)] -> IO [(Int, Int)]
select _      _    _ []          = return []
select _      _    0 s           = return s
select parent mark n ((w, v):ws) = do
  p <- readArray parent v
  used <- readArray mark p
  if used
    then do
      l <- select parent mark n ws
      return $ (w, v):l
    else do
      writeArray mark p True
      s <- readArray parent (-1)
      writeArray parent (-1) $ s + w
      select parent mark (n-1) ws

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
