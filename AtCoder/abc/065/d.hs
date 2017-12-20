import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO

main = do
  n <- readLn :: IO Int
  [x, y] <- transpose <$> getInt2DListBC
  parent <- newArray (1, n) 0 :: IO (IOUArray Int Int)
  let pointX = zip [1..n] x
      pointY = zip [1..n] y
      sortedX = sortBy (\x y -> compare (snd x) (snd y)) pointX
      sortedY = sortBy (\x y -> compare (snd x) (snd y)) pointY
      edge = sortBy compEdge $ (makeEdge sortedX) ++ (makeEdge sortedY)
  print =<< greedy parent edge (n-1) 0

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

makeEdge :: [(Int, Int)] -> [(Int, Int, Int)]
makeEdge (_:[]) = []
makeEdge (x:y:ys) = (fst x, fst y, abs $ (snd x) - (snd y)) : makeEdge (y:ys)

compEdge :: (Int, Int, Int) -> (Int, Int, Int) -> Ordering
compEdge (_, _, x) (_, _, y) = compare x y

greedy :: IOUArray Int Int -> [(Int, Int, Int)] -> Int -> Int -> IO Int
greedy parent ((i, j, w):es) n k
  | n == k    = return 0
  | otherwise = do
    pI <- getParent parent i
    pJ <- getParent parent j
    if pI == pJ then greedy parent es n k
                else do
                  writeArray parent pI pJ
                  sum <- greedy parent es n $ k + 1
                  return $ w + sum

getParent :: IOUArray Int Int -> Int -> IO Int
getParent memo i = do
  parent <- readArray memo i
  case parent of
    0 -> return i
    _ -> do
      pp <- getParent memo parent
      writeArray memo i pp
      return pp
