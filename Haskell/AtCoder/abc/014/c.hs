import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

main = do
  getLine
  input <- (\(x:y:_) -> zip x y) . transpose <$> getIntListBC
  memoS <- newArray (0, 1000001) 0 :: IO (IOUArray Int Int)
  memoT <- newArray (0, 1000001) 0 :: IO (IOUArray Int Int)
  ss <- getElems =<< foldM countS memoS input
  tt <- getElems =<< foldM countT memoT input
  let table = zip ss tt
  putStrLn . show . maximum $ count 0 table

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [[Int]]
getIntListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

memoize :: IOUArray Int Int -> Int -> IO (IOUArray Int Int)
memoize memo x = do
  n <- readArray memo x
  writeArray memo x (n+1)
  return memo

countS :: IOUArray Int Int -> (Int, Int) -> IO (IOUArray Int Int)
countS memo (s, _) = memoize memo s

countT :: IOUArray Int Int -> (Int, Int) -> IO (IOUArray Int Int)
countT memo (_, t) = memoize memo $ t + 1

count :: Int -> [(Int, Int)] -> [Int]
count n []     = []
count n (x:xs) = let nn = n + (fst x - snd x)
                    in nn:count nn xs
