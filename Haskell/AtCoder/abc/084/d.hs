import qualified Data.ByteString.Char8 as BC
import Data.Array.IO
import Data.Maybe (fromJust)
import Data.List
import Control.Monad

type Table = IOUArray Int Int

maxX = 10^5

main = do
  q <- readLn :: IO Int
  query <- getInt2DListBC
  table <- newArray (1, maxX) 0 :: IO Table
  prime table 1 maxX [i | i <- [3..maxX], odd i == True]
  p <- filter (/=0) <$> getElems table
  isPrime <- newArray (1, maxX) False :: IO (IOUArray Int Bool)
  foldM check isPrime p
  count <- newArray (0, maxX) 0 :: IO Table
  countMemo isPrime count p 3
  ans <- mapM (solve count) query
  putStr $ unlines . map show $ ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

countMemo :: IOUArray Int Bool -> Table -> [Int] -> Int -> IO Table
countMemo isPrime table [] i = do
    c <- readArray table (i-1)
    repeatWrite table (i, maxX) $ c + 1
    return table
countMemo isPrime table (p:ps) i = do
  b <- readArray isPrime $ div (p+1) 2
  if b
    then do
      c <- readArray table (i-1)
      repeatWrite table (i, p-1) $ c + 1
      countMemo isPrime table ps p
    else do
      countMemo isPrime table ps i

check :: IOUArray Int Bool -> Int -> IO (IOUArray Int Bool)
check table i = do
  writeArray table i True
  return table

solve :: Table -> [Int] -> IO Int
solve table [i, j] = do
  l <- readArray table $ i - 1
  r <- readArray table j
  return $ r - l

repeatWrite :: IOUArray Int Int -> (Int, Int) -> Int -> IO (IOUArray Int Int)
repeatWrite memo (i, j) c = do
  return =<< foldM (write c) memo [i..j]

write :: Int -> IOUArray Int Int -> Int -> IO (IOUArray Int Int)
write c memo x = do
  writeArray memo x c
  return memo

prime :: Table -> Int -> Int -> [Int] -> IO Table
prime table pn n []     = return table
prime table pn n x@(i:is) = do
  if i^2 <= n
    then do
      writeArray table (pn+1) i
      let is' = filter ((/=0) . flip mod i) is
      prime table (pn+1) n is'
    else do
      let len = length x
          idx = [pn+1..pn+len]
      prime' $ zip idx x
      return table
            where prime' :: [(Int, Int)] -> IO Table
                  prime' [] = return table
                  prime' ((i, n):ss) = do
                    writeArray table i n
                    prime' ss
