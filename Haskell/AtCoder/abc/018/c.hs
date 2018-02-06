import Data.Array.IO
import Data.List
import Control.Monad

type Arr = IOUArray (Int, Int) Int

main = do
  [r,c,k] <- map read . words <$> getLine :: IO [Int]
  s <- replicateM r getLine
  up <- newArray ((1, 1), (r, c)) 0 :: IO Arr
  down <- newArray ((1, 1), (r, c)) 0 :: IO Arr
  countD down 1 $ transpose s
  countU up 1 $ map reverse $ transpose s
  uList <- cut c <$> getElems up
  dList <- cut c <$> getElems down
  ans <- concat <$> mapM (solve up down k c) [1..r]
  print $ length $ filter (==True) ans

solve :: Arr -> Arr -> Int -> Int -> Int -> IO [Bool]
solve up down k c i = do
  let j = [k..c-k+1]
  mapM (solve' i) j
    where solve' i j = do
            l <- judgeL up down i j k
            r <- judgeR up down i j k
            return $ l && r

judgeL :: Arr -> Arr -> Int -> Int -> Int -> IO Bool
judgeL up down i j 0 = return True
judgeL up down i j k = do
  x <- readArray up (i, j)
  y <- readArray down (i, j)
  if x >= k && y >= k
    then judgeL up down i (j-1) (k-1)
    else return False

judgeR :: Arr -> Arr -> Int -> Int -> Int -> IO Bool
judgeR up down i j 0 = return True
judgeR up down i j k = do
  x <- readArray up (i, j)
  y <- readArray down (i, j)
  if x >= k && y >= k
    then judgeR up down i (j+1) (k-1)
    else return False

cut :: Int -> [Int] -> [[Int]]
cut _   [] = []
cut len x  = (take len x) : (cut len $ drop len x)

countD :: Arr -> Int -> [String] -> IO ()
countD arr _ []     = return ()
countD arr i (s:ss) = do
  countD' arr i 1 0 s
  countD arr (i+1) ss

countD' :: Arr -> Int -> Int -> Int -> String -> IO ()
countD' arr _   _ _ []       = return ()
countD' arr row i c ('o':as) = do
  writeArray arr (i, row) $ c + 1
  countD' arr row (i+1) (c+1) as
countD' arr row i c ('x':as) = do
  countD' arr row (i+1) 0 as

countU :: Arr -> Int -> [String] -> IO ()
countU arr _ []     = return ()
countU arr i (s:ss) = do
  countU' arr i (length s) 0 s
  countU arr (i+1) ss

countU' :: Arr -> Int -> Int -> Int -> String -> IO ()
countU' arr _   _ _ []       = return ()
countU' arr row i c ('o':as) = do
  writeArray arr (i, row) $ c + 1
  countU' arr row (i-1) (c+1) as
countU' arr row i c ('x':as) = do
  countU' arr row (i-1) 0 as
