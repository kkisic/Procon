import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

main = do
  [n, w] <- map read . words <$> getLine :: IO [Int]
  input <- sortBy (\x y -> compare (head x) (head y)) <$> getInt2DListBC
  table <- newArray ((1, 0), (4, 100)) 0 :: IO (IOUArray (Int, Int) Int)
  let [ww, vv] = transpose input
      num = map length . group $ ww
      wList = map head . group $ ww
      vList = split num vv
  foldM (memoize vList) table [1..length num]
  ans <- solve table w wList num
  print $ maximum ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

split :: [Int] -> [Int] -> [[Int]]
split [] _     = []
split (n:ns) v = (reverse . sort . take n $ v) : (split ns $ drop n v)

solve :: IOUArray (Int, Int) Int -> Int -> [Int] -> [Int] -> IO [Int]
solve table w wList num = do
  case length wList of
    1 -> do
      let pattern = [[i] | i <- [0..(num !! 0)]]
      return =<< mapM (solve' table w wList) pattern
    2 -> do
      let pattern = [[i, j] | i <- [0..(num !! 0)], j <- [0..(num !! 1)]]
      return =<< mapM (solve' table w wList) pattern
    3 -> do
      let pattern = [[i, j, k] | i <- [0..(num !! 0)], j <- [0..(num !! 1)], k <- [0..(num !! 2)]]
      return =<< mapM (solve' table w wList) pattern
    4 -> do
      let pattern = [[i, j, k, l] | i <- [0..(num !! 0)], j <- [0..(num !! 1)], k <- [0..(num !! 2)], l <- [0..(num !! 3)]]
      return =<< mapM (solve' table w wList) pattern

solve' :: IOUArray (Int, Int) Int -> Int -> [Int] -> [Int] -> IO Int
solve' memo w wList p
  | w < (sum $ zipWith (*) wList p) = return 0
  | otherwise = do
    s <- mapM (readArray memo) $ zip [1..4] p
    return $ sum s

memoize :: [[Int]] -> IOUArray (Int, Int) Int -> Int -> IO (IOUArray (Int, Int) Int)
memoize v memo i = do
  foldM (sumValue i) memo $ zip [1..100] (v !! (i-1))
  return memo

sumValue :: Int -> IOUArray (Int, Int) Int -> (Int, Int) -> IO (IOUArray (Int, Int) Int)
sumValue w memo (i, v) = do
  s <- readArray memo (w, i-1)
  writeArray memo (w, i) $ s + v
  return memo
