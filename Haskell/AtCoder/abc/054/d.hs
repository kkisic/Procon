import Data.Array.IO
import Data.List
import Control.Monad

type Memo = IOUArray (Int, Int, Int) Int
type Index = (Int, Int)

infinite = maxBound :: Int

main = do
  [n,ma,mb] <- map read . words <$> getLine :: IO [Int]
  item <- map (map read . words) . lines <$> getContents :: IO [[Int]]
  memo <- newArray ((0, 0, 0), (n, 400, 400)) infinite :: IO Memo
  writeArray memo (0, 0, 0) 0
  dp memo [0..(n-1)] item
  let index = [(a, b) | a <- [1..400], b <- [1..400]]
  ans <- filter (/=infinite) <$> mapM (getAns memo n ma mb) index
  if ans /= [] then print $ minimum ans
               else print (-1)

dp :: Memo -> [Int] -> [[Int]] -> IO Memo
dp memo []     []     = return memo
dp memo (i:is) (m:ms) = do
  let index = [(a,b) | a <- [0..400], b <- [0..400]]
  memo' <- foldM (memoize m i) memo index
  dp memo' is ms >>= return

memoize :: [Int] -> Int -> Memo -> Index -> IO Memo
memoize [a,b,c] n memo (ma,mb) = do
  x <- readArray memo (n, ma, mb)
  if x /= infinite
    then do
      y <- readArray memo (n+1, ma, mb)
      writeArray memo (n+1, ma, mb) $ min x y
      z <- readArray memo (n+1, ma+a, mb+b)
      writeArray memo (n+1, ma+a, mb+b) $ min z $ x + c
      return memo
    else do
      return memo

getAns :: Memo -> Int -> Int -> Int -> Index -> IO Int
getAns memo n ma mb (a, b)
  | ma * b == mb * a = do
    ans <- readArray memo (n, a, b)
    return ans
  | otherwise        = return infinite
