import Data.List
import Data.Array.IO
import Control.Monad

type Vertex = (Int, [Int])

main = do
  [n, m] <- map read . words <$> getLine :: IO [Int]
  edge <- (\[x, y] -> zip x y) . transpose . map (map read . words) . lines <$> getContents :: IO [(Int, Int)]
  let v = [(i, []) | i <- [1..n]]
  print =<< foldM (solve n v edge) 0 edge

makeMark :: Int -> IO (IOUArray Int Bool)
makeMark n = newArray (1, n) False

makeGraph :: [Vertex] -> (Int, Int) -> [Vertex]
makeGraph v (i, j) = write i j $ write j i v

write :: Int -> Int -> [Vertex] -> [Vertex]
write x y v = take (x-1) v ++ [(x, y:(snd $ v !! (x-1)))] ++ drop x v

search :: [Vertex] -> IOUArray Int Bool -> Int -> IO (IOUArray Int Bool)
search [] mark i = return mark
search graph mark i = do
  let (v, neighbors) = graph !! (i - 1)
  b <- readArray mark i
  case b of
    True -> do
      return mark
    False -> do
      writeArray mark i True
      return =<< foldM (search graph) mark neighbors

solve :: Int -> [Vertex] -> [(Int, Int)] -> Int -> (Int, Int) -> IO Int
solve n v edges brigde e = do
  let graph = foldl makeGraph v $ delete e edges
  mark <- makeMark n
  search graph mark 1
  ans <- and <$> getElems mark
  return $ if ans then brigde else brigde + 1
