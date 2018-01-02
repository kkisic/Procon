import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Memo = IOUArray Int Int

main = do
  n <- readLn :: IO Int
  input <- getIntListBC
  piller <- newListArray (1, n) input :: IO Memo
  memo <- newArray (1, n) 0 :: IO Memo
  let idx = [2..n]
  foldM (dp piller) memo idx
  print =<< readArray memo n

dp :: Memo -> Memo -> Int -> IO Memo
dp piller memo 2 = do
  p1 <- readArray piller 1
  p2 <- readArray piller 2
  writeArray memo 2 $ abs $ p1 - p2
  return memo
dp piller memo i = do
  p1 <- readArray piller $ i
  p2 <- readArray piller $ i - 1
  p3 <- readArray piller $ i - 2
  m2 <- readArray memo $ i - 1
  m3 <- readArray memo $ i - 2
  writeArray memo i $ min ((+m2) . abs $ p1 - p2) ((+m3) . abs $ p1 - p3)
  return memo

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
