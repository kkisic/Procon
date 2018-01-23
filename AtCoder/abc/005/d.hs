import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Arr2D = IOUArray (Int, Int) Int
type Arr = IOUArray Int Int
type Point = (Int, Int)

main = do
  n <- readLn :: IO Int
  area <- concat <$> replicateM n getIntListBC
  q <- readLn :: IO Int
  p <- getIntListBC'
  cum <- newArray ((0, 0), (n, n)) 0 :: IO Arr2D
  maxC <- newArray (1, n^2) 0 :: IO Arr
  let idx = [(i, j) | i <- [1..n], j <- [1..n]]
  count cum idx area
  foldM accum2D cum idx
  solve cum maxC n
  foldM update maxC [2..n^2]
  ans <- mapM (readArray maxC) p
  putStr . unlines . map show $ ans

update :: Arr -> Int -> IO Arr
update maxC p = do
  x <- readArray maxC $ p-1
  y <- readArray maxC p
  writeArray maxC p $ max x y
  return maxC

solve :: Arr2D -> Arr -> Int -> IO Arr
solve cum maxC n = do
  let p = [(i, j, k, l) | i <- [0..n-1], j <- [0..n-1], k <- [i+1..n], l <- [j+1..n]]
  foldM (solve' cum) maxC p

solve' :: Arr2D -> Arr -> (Int, Int, Int, Int) -> IO Arr
solve' cum maxC (i, j, k, l) = do
  let s = (k-i) * (l-j)
  x <- readArray maxC s
  y <- query cum (i, j, k, l)
  writeArray maxC s $ max x y
  return maxC

query :: Arr2D -> (Int, Int, Int, Int) -> IO Int
query cum (i, j, k, l) = do
  a <- readArray cum (i, j)
  b <- readArray cum (i, l)
  c <- readArray cum (k, j)
  d <- readArray cum (k, l)
  return $ a + d - b - c

accum2D :: Arr2D -> Point -> IO Arr2D
accum2D cum (i, j) = do
  x <- readArray cum (i-1, j)
  y <- readArray cum (i, j-1)
  z <- readArray cum (i-1, j-1)
  w <- readArray cum (i, j)
  writeArray cum (i, j) $ x + y - z + w
  return cum

count :: Arr2D -> [(Int, Int)] -> [Int] -> IO ()
count arr []          []     = return ()
count arr ((x, y):ps) (v:vs) = do
  writeArray arr (x, y) v
  count arr ps vs

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getIntListBC' :: IO [Int]
getIntListBC' = map bsToInt . BC.lines <$> BC.getContents
