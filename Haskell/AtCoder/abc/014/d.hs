import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.Bits
import Control.Monad

main = do
  n <- readLn :: IO Int
  edge <- map (\[x,y] -> (x, y)) <$> replicateM (n-1) getIntListBC
  q <- readLn :: IO Int
  append <- map (\[x,y] -> (x, y)) <$> getInt2DListBC
  let graph = foldl makeGraph M.empty edge
  depth <- newArray (1, n) $ 0 :: IO Arr
  table <- newArray ((1, 0),  (n, maxLog-1)) 1 :: IO Arr2D
  dfs graph 1 1 table depth 1
  foldM (makeTableLCA n) table [0..maxLog-2]
  ans <- mapM (solve depth table) append
  putStr $ unlines . map show $ ans

printTable :: Int -> [Int] -> IO ()
printTable _ []   = return ()
printTable n list = do
  print $ take n list
  printTable n $ drop n list

type Arr = IOUArray Int Int
type Arr2D = IOUArray (Int, Int) Int

maxLog = 18

solve :: Arr -> Arr2D -> Edge -> IO Int
solve depth table (u, v) = do
  a <- lca depth table u v
  d <- readArray depth a
  x <- readArray depth u
  y <- readArray depth v
  return $ (x - d) + (y - d) + 1

--DFS : 前pre 現在v 深さd
dfs :: Graph -> Int -> Int -> Arr2D -> Arr -> Int -> IO Arr
dfs graph pre d table depth v = do
  writeArray table (v, 0) pre
  writeArray depth v d
  let ne = filter (/=pre) . fromJust . M.lookup v $ graph
  if ne /= []
    then foldM (dfs graph v (d+1) table) depth ne
    else return depth

makeTableLCA :: Int -> Arr2D -> Int -> IO Arr2D
makeTableLCA n table k = do
  foldM make table [1..n]
  where make :: Arr2D -> Int -> IO Arr2D
        make t v = do
          p <- readArray t (v, k)
          if p == 1
            then return t
            else do
              pp <- readArray t (p, k)
              writeArray t (v, k+1) pp
              return t

ancestor :: Arr2D -> Int -> Int -> IO Int
ancestor table v depth =
  foldM anc v [0..maxLog-1]
  where anc :: Int -> Int -> IO Int
        anc vv i =
          if shiftR depth i .&. 1 == 1
            then readArray table (vv, i)
            else return vv

lca :: Arr -> Arr2D -> Int -> Int -> IO Int
lca depth table u v = do
  ud <- readArray depth u
  vd <- readArray depth v
  if ud > vd
    then lca depth table v u
    else do
      v' <- ancestor table v (vd - ud)
      if u == v'
        then return u
        else do
          k <- lowerBound (judge table u v') (-1) $ 10^5
          ancestor table u k

judge :: Arr2D -> Int -> Int -> Int -> IO Bool
judge table u v i = do
  up <- ancestor table u i
  vp <- ancestor table v i
  return $ up == vp

lowerBound :: (Int -> IO Bool) -> Int -> Int -> IO Int
lowerBound f lb ub
  | ub - lb == 1 = return ub
  | otherwise = do
    let mid = div (lb + ub) 2
    flag <- f mid
    if flag
      then lowerBound f lb mid
      else lowerBound f mid ub

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

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
