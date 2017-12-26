import qualified Data.ByteString.Char8 as BC
import qualified Data.Map.Strict as M
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

type Memo = IOUArray Int Int
type Edge = (Int, Int)

main = do
  [n,k,l] <- map read . words <$> getLine :: IO [Int]
  road <- (\[x, y] -> zip x y) . transpose <$> replicateM k getIntListBC
  railway <- (\[x, y] -> zip x y) . transpose <$> replicateM l getIntListBC
  repRoad <- newListArray (1, n) [1..n] :: IO Memo
  repRailway <- newListArray (1, n) [1..n] :: IO Memo
  unionFind repRoad road
  unionFind repRailway railway
  foldM (setRepresentative repRoad) repRailway $ reverse [1..n]
  roadC <- getElems repRoad
  railwayC <- getElems repRailway
  let pair = zip roadC railwayC
      sortedPair = map (\x -> (head x, length x)) . group . sort $ pair
      arr = M.fromList sortedPair
  putStrLn . unwords . map show $ solve arr pair

unionFind :: Memo -> [Edge] -> IO Memo
unionFind memo [] = return memo
unionFind memo ((i, j):es) = do
  pI <- getRepresentative memo i
  pJ <- getRepresentative memo j
  if pI == pJ then unionFind memo es
              else do
                writeArray memo pI pJ
                unionFind memo es

getRepresentative :: Memo -> Int -> IO Int
getRepresentative memo i = do
  parent <- readArray memo i
  if parent == i
    then return i
    else do
      pp <- getRepresentative memo parent
      writeArray memo i pp
      return pp

setRepresentative :: Memo -> Memo -> Int -> IO Memo
setRepresentative road railway i = do
  pI <- getRepresentative road i
  qI <- getRepresentative railway i
  writeArray road i pI
  writeArray railway i qI
  return railway

solve _ []     = []
solve m (x:xs) = let v = fromJust $ M.lookup x m
                 in v : (solve m xs)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
