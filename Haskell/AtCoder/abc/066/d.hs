import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Memo = IOUArray Int Int

modN :: Int
modN = 10^9+7

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  check <- newArray (1, n) 0 :: IO Memo
  l <- numbering check a 1
  table <- newArray (0, n+1) 0 :: IO Memo
  makeTable table (n+1) (n+1)
  let k = [1..n+1]
      dup = n - l - 1
      cn = fact (n+1)
      cnl = fact dup
  ans <- mapM (solve table cn cnl n l) k
  putStr $ unlines . map show $ ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

numbering :: Memo -> [Int] -> Int -> IO Int
numbering memo [] n = return 0
numbering memo (i:is) n = do
  c <- readArray memo i
  case c of
    0 -> do
      writeArray memo i n
      return =<< numbering memo is $ n + 1
    _ -> do
      return $ n - c - 1

--x^n (mod modN)
(|^) :: Int -> Int -> Int
(|^) x n
  | n == 0    = 1
  | even n    = (mod (x * x) modN) |^ (n `div` 2)
  | otherwise = (flip mod modN) . (*x) $ x |^ (n - 1)

--x! (mod modN)
fact :: Int -> Int
fact n
  | n == 0    = 1
  | otherwise = (flip mod modN) . (*n) $ fact (n-1)

makeTable :: Memo -> Int -> Int -> IO Memo
makeTable table n (-1) = return table
makeTable table n i
  | n == i = do
    writeArray table i $ (fact n) |^ (10^9+5)
    makeTable table i $ i-1
  | otherwise = do
    ie <- readArray table (i+1)
    writeArray table i $ flip mod modN $ ie * (i+1)
    makeTable table i $ i-1

comb :: Memo -> Int -> Int -> Int -> IO Int
comb memo cn n k
  |n >= k = do
    ik <- readArray memo k
    ink <- readArray memo $ n - k
    let tmp = flip mod modN $ cn * ik
        ans = flip mod modN $ tmp * ink
    return ans
  | otherwise = return 0

solve :: Memo -> Int -> Int -> Int -> Int -> Int -> IO Int
solve table cn cnl n l k = do
  x <- comb table cn (n+1) k
  y <- comb table cnl (n-l-1) (k-1)
  return $ flip mod modN $ modN + x - y
