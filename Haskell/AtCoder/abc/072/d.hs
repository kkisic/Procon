import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

main = do
  n <- readLn :: IO Int
  p <- getIntListBC
  memo <- newListArray (0, n+1) (0:p) :: IO (IOUArray Int Int)
  let index = [1..n]
  foldM swap memo index
  print =<< readArray memo 0

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

swap :: IOUArray Int Int -> Int -> IO (IOUArray Int Int)
swap memo i = do
  count <- readArray memo 0
  n <- readArray memo i
  m <- readArray memo $ i + 1
  let (nn, mm, count') = if i == n then (m, n, count + 1) else (n, m, count)
  writeArray memo i nn
  writeArray memo (i+1) mm
  writeArray memo 0 count'
  return memo
