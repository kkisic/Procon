import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Data.Int
import Control.Monad

type Arr = IOUArray (Int, Int) Int
type PointC = (Int, Int, Char)
type Point = (Int, Int)

main = do
  [n,k] <- map read . words <$> getLine :: IO [Int]
  t <- map (compression k) <$> getInt2DListBC
  cum <- newArray ((0, 0), (2*k, 2*k)) 0 :: IO Arr
  ans <- newArray ((0, 0), (2*k, k)) 0 :: IO Arr
  let  pos = [(i, j) | i <- [1..k], j <- [1..k]] ++ [(i, j) | i <- [k+1..2*k], j <- [1..k]]
  foldM (count k) cum t
  accum2D k cum (1, 1)
  foldM (solve k cum) ans pos
  x <- maximum <$> getElems ans
  print x

solve :: Int -> Arr -> Arr -> Point -> IO Arr
solve k cum ans (i, j)
  | i+k <= 2*k && j+k <= 2*k = do
    a <- query cum (i, j, i+k, j+k)
    b <- query cum (0, j+k, i, 2*k)
    c <- query cum (i+k, 0, 2*k, j)
    d <- query cum (i+k, j+k, 2*k, 2*k)
    e <- query cum (0, 0, i, j)
    writeArray ans (i, j) $ a + b + c + d + e
    return ans
  | otherwise = do
    a <- query cum (i, j, 2*k, j+k)
    b <- query cum (i-k, j+k, i, 2*k)
    c <- query cum (0, j, i-k, j+k)
    d <- query cum (i-k, 0, i, j)
    writeArray ans (i, j) $ a + b + c + d
    return ans

query :: Arr -> (Int, Int, Int, Int) -> IO Int
query cum (i, j, k, l) = do
  a <- readArray cum (i, j)
  b <- readArray cum (i, l)
  c <- readArray cum (k, j)
  d <- readArray cum (k, l)
  return $ a + d - b - c

next :: Int -> Point -> Point
next k (x, y)
  | y == 2*k = (x+1, 1)
  | otherwise = (x, y+1)

accum2D :: Int -> Arr -> Point -> IO ()
accum2D k cum (i, j)
  | i == 2*k+1 = return ()
  | otherwise = do
    x <- readArray cum (i-1, j)
    y <- readArray cum (i, j-1)
    z <- readArray cum (i-1, j-1)
    w <- readArray cum (i, j)
    writeArray cum (i, j) $ x + y - z + w
    accum2D k cum $ next k (i, j)

compression :: Int -> PointC -> Point
compression k (x, y, 'B') = (mod x $ 2*k, mod y $ 2*k)
compression k (x, y, 'W') = (mod x $ 2*k, mod (y+k) $ 2*k)

count :: Int -> Arr -> Point -> IO Arr
count k arr (x,y) = do
  inc arr (x+1, y+1)
  return arr

inc :: Arr -> (Int, Int) -> IO ()
inc arr p = do
  x <- readArray arr p
  writeArray arr p $ x + 1

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [PointC]
getInt2DListBC = map ((\[x,y,z] -> (bsToInt x, bsToInt y, head $ BC.unpack z)) . BC.words) . BC.lines <$> BC.getContents
