import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

type Arr = IOUArray Int Int

main = do
  n <- readLn :: IO Int
  input <- getInt2DListBC
  print =<< lowerBound n input

judge :: [[Int]] -> Int -> Int -> IO Bool
judge balloon n t = do
  let t' = filter (<=n) $ map (time t) balloon
      m = if t' == [] then 0 else minimum t'
  if m < 0
    then return False
    else do
      b <- bsort n t'
      return b

time :: Int -> [Int] -> Int
time t [h,s] = div (t-h) s

lowerBound :: Int -> [[Int]] -> IO Int
lowerBound n balloon = innerLB (negate 1) (10^18)
  where innerLB lb ub
          | ub - lb > 1 = do
                          let mid = lb + (ub - lb) `div` 2
                          flag <- judge balloon n mid
                          if flag
                               then innerLB lb mid
                               else innerLB mid ub
          | otherwise   = return ub

bsort :: Int -> [Int] -> IO Bool
bsort n x = do
  arr <- newArray (0, n) 0 :: IO Arr
  foldM bsort' arr x
  l <- getElems arr
  return $ check l 0 1
    where bsort' :: Arr -> Int -> IO Arr
          bsort' arr a = do
            c <- readArray arr a
            writeArray arr a $ c+1
            return arr
          check :: [Int] -> Int -> Int -> Bool
          check []     _   _ = True
          check (l:ls) sum n
            | l+sum <= n = check ls (sum+l) $ n+1
            | otherwise  = False

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

