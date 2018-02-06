import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Memo = IOUArray Int Int
type EdgeW = (Int, Int, Int)

main = do
  [n, m] <- map read . words <$> getLine :: IO [Int]
  edge <- sortBy (\(_, _, x) (_, _, y) -> compare y x) . map (\[x,y,z] -> (x,y,z)) <$> replicateM m getIntListBC
  q <- readLn :: IO Int
  people' <- map (\[x,y] -> (x, y)) <$> replicateM q getIntListBC
  let people = sortBy (\(_, x, _) (_, y, _) -> compare y x) $ addNum people' [1..]
      (_, _, first) = head people
  rep <- newListArray (1, n) [1..n] :: IO Memo
  connected <- newArray (1, n) 1 :: IO Memo
  ans <- newArray (1, q) 0 :: IO Memo
  unionFind connected rep ans first edge people
  ansList <- getElems ans
  putStr $ unlines . map show $ ansList

unionFind :: Memo -> Memo -> Memo -> Int -> [EdgeW] -> [(Int, Int, Int)] -> IO Memo
unionFind connected rep ans i _ [] = return ans
unionFind connected rep ans i [] p@((v,wp,n):ps) = do
    pv <- getRepresentative rep v
    num <- readArray connected pv
    writeArray ans n num
    unionFind connected rep ans n [] ps
unionFind connected rep ans i e@((i1,j1,we1):es) p@((v,wp,n):ps)
  | we1 <= wp = do
    pv <- getRepresentative rep v
    num <- readArray connected pv
    writeArray ans n num
    unionFind connected rep ans n e ps
  | we1 > wp = do
    pI <- getRepresentative rep i1
    pJ <- getRepresentative rep j1
    if pI == pJ then unionFind connected rep ans n es p
                else do
                  cI <- readArray connected pI
                  cJ <- readArray connected pJ
                  writeArray rep pI pJ
                  writeArray connected pI $ cI + cJ
                  writeArray connected pJ $ cI + cJ
                  unionFind connected rep ans n es p

getRepresentative :: Memo -> Int -> IO Int
getRepresentative memo i = do
  parent <- readArray memo i
  if i == parent
    then return i
    else do
      pp <- getRepresentative memo parent
      writeArray memo i pp
      return pp

addNum :: [(Int, Int)] -> [Int] -> [(Int, Int, Int)]
addNum []          _      = []
addNum ((v, w):ps) (x:xs) = (v, w, x):addNum ps xs

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
