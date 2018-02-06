import qualified Data.IntMap as M
import qualified Data.Sequence as S
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Arr = IOUArray Int Int
type Mark = IOUArray Int Int
type Queue = S.Seq Int

modN = 10^9+7
inf = 10^5

main = do
  n <- readLn :: IO Int
  [a,b] <- map read . words <$> getLine :: IO [Int]
  m <- readLn :: IO Int
  edge <- map (\[x,y] -> (x,y)) . map (map read . words) . lines <$> getContents :: IO [(Int, Int)]
  mark <- newArray (1, n) inf :: IO Mark
  pattern <- newArray (1, n) 0 :: IO Arr
  let graph = foldl makeGraph M.empty edge
      queue = S.fromList [a]
  writeArray pattern a 1
  solve graph pattern mark queue
  ans <- readArray pattern b
  print ans

solve :: Graph -> Arr -> Mark -> Queue -> IO ()
solve graph arr mark queue
  | S.length queue > 0 = do
    let v = fst . dequeue $ queue
        q' = S.drop 1 queue
    marked <- readArray mark v
    p <- readArray arr v
    let ne = fromJust $ M.lookup v graph
    q'' <- foldM (enqueue arr mark p marked) q' ne
    solve graph arr mark q''
  | otherwise = return ()

enqueue :: Arr -> Mark -> Int -> Int -> Queue -> Int -> IO Queue
enqueue arr mark x depth q v = do
  marked <- readArray mark v
  if marked /= inf
    then do
      if marked > depth
        then do
          p <- readArray arr v
          writeArray arr v $ flip mod modN $ p + x
          return q
        else return q
    else do
      writeArray mark v $ depth + 1
      p <- readArray arr v
      writeArray arr v $ flip mod modN $ p + x
      return $ q S.|> v

dequeue :: S.Seq a -> (a, S.Seq a)
dequeue que = case S.viewl que of
                S.EmptyL -> error "Empty Queue"
                x S.:< xs -> (x, xs)

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
