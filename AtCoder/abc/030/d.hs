import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Array.Unboxed
import Data.Array.IO
import Data.Char
import Data.List

type Mark = IOUArray Int Bool

main = do
  [n,a] <- map read . words <$> getLine :: IO [Int]
  k <- getLine
  b <- getIntListBC
  marked <- newArray (1, n) False :: IO Mark
  let dict = listArray (1, n) b :: UArray Int Int
      kLen = length k
  start <- count dict a marked
  let toStart = count' dict a start 0
      cc = closed dict start start
  if kLen <= 6
    then do
      let step = read k :: Int
      if step < toStart
        then print $ toDest dict a step
        else do
          let step' = mod (step-toStart) $ length cc
          print $ cc !! step'
    else do
      let ss = subBignum k toStart
          step = modBignum ss (length cc) 0
      print $ cc !! step

modBignum :: String -> Int -> Int -> Int
modBignum []     _    x = x
modBignum (n:ns) modN x =
  let n' = digitToInt n
  in modBignum ns modN $ mod (x * 10 + n') modN

subBignum :: String -> Int -> String
subBignum s n =
  let numS = read s :: Integer
  in show $ numS - (toInteger n)


--return : (length, closed_start)
count :: UArray Int Int -> Int -> Mark -> IO Int
count dict now mark = do
  let next = dict ! now
  x <- readArray mark next
  if x
    then return next
    else do
      writeArray mark next True
      count dict next mark

count' :: UArray Int Int -> Int -> Int -> Int -> Int
count' dict src dst c =
  let next = dict ! src
  in if next == dst
        then c+1
        else count' dict next dst $ c+1

closed :: UArray Int Int -> Int -> Int -> [Int]
closed dict src dst =
  let next = dict ! src
  in if next == dst
        then [src]
        else src : (closed dict next dst)

toDest :: UArray Int Int -> Int -> Int -> Int
toDest dict src 0 = src
toDest dict src len =
  let next = dict ! src
  in toDest dict next $ len - 1

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
