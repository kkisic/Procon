import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  switch <- newArray (1, n) 0 :: IO (IOUArray Int Int)
  initS switch [1..n] a
  check <- newArray (1, n) False :: IO (IOUArray Int Bool)
  ans <- solve check switch 1 0
  print ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents

initS :: IOUArray Int Int -> [Int] -> [Int] -> IO (IOUArray Int Int)
initS memo []     []     = return memo
initS memo (i:is) (a:as) = do
  writeArray memo i a
  initS memo is as

solve :: IOUArray Int Bool -> IOUArray Int Int -> Int -> Int -> IO Int
solve check switch 2 c = return c
solve check switch i c = do
  b <- readArray check i
  if b then return (-1)
       else do
         writeArray check i True
         next <- readArray switch i
         solve check switch next $ c + 1
