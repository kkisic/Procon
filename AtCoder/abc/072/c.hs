import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  memoS <- newArray ((-1), 100002) 0 :: IO (IOUArray Int Int)
  memoE <- newArray ((-1), 100002) 0 :: IO (IOUArray Int Int)
  foldM memoizeS memoS a
  foldM memoizeE memoE a
  s <- getElems memoS
  e <- getElems memoE
  let table = zip s e
  putStrLn . show . maximum $ count 0 table

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

memoizeS :: IOUArray Int Int -> Int -> IO (IOUArray Int Int)
memoizeS memo x = do
  n <- readArray memo (x-1)
  writeArray memo (x-1) (n+1)
  return memo

memoizeE :: IOUArray Int Int -> Int -> IO (IOUArray Int Int)
memoizeE memo x = do
  n <- readArray memo (x+2)
  writeArray memo (x+2) (n+1)
  return memo

count :: Int -> [(Int, Int)] -> [Int]
count n []     = []
count n (x:xs) = let nn = n + (fst x - snd x)
                    in nn : count nn xs
