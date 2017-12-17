import Data.List
import Data.Array.IO
import Control.Monad
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

size = 8000

main = do
  s <- map (length . BC.unpack) . BC.split 'T' <$> BC.getLine
  (x:y:_) <- map (read :: String -> Int) . words <$> getLine
  memoX <- newArray ((0, (-size)), (size, size)) False :: IO (IOUArray (Int, Int) Bool)
  memoY <- newArray ((0, (-size)), (size, size)) False :: IO (IOUArray (Int, Int) Bool)
  let (xI', yI) = split s ([], [])
      xI@(i:is) = if head s /= 0
                    then filter (/=0) xI'
                    else 0:(filter (/=0) $ tail xI')
  writeArray memoX (0, 0) True
  writeArray memoX (1, i) True
  writeArray memoY (0, 0) True
  dp memoX 2 is
  dp memoY 1 yI
  resultX <- readArray memoX (length xI, x)
  resultY <- readArray memoY (length yI, y)
  if resultX && resultY then putStrLn "Yes"
                        else putStrLn "No"

split :: [Int] -> ([Int], [Int]) -> ([Int], [Int])
split []       (x, y) = (reverse x, filter (/=0) $ reverse y)
split (s:[])   (x, y) = (reverse (s:x), reverse y)
split (s:t:ts) (x, y) = split ts ((s:x), (t:y))

dp :: IOUArray (Int, Int) Bool -> Int -> [Int] -> IO (IOUArray (Int, Int) Bool)
dp memo _ []     = return memo
dp memo 1 (d:ds) = do
  writeArray memo (1, d) True
  writeArray memo (1, (-d)) True
  dp memo 2 ds >>= return
dp memo n (d:ds) = do
  memo' <- foldM (memoize n d) memo [(-size)..size]
  dp memo' (n+1) ds >>= return

memoize :: Int -> Int -> IOUArray (Int, Int) Bool -> Int -> IO (IOUArray (Int, Int) Bool)
memoize n d memo x
  | x - d >= (-size) && x + d <= size = do
    a <- readArray memo (n-1, x-d)
    b <- readArray memo (n-1, x+d)
    writeArray memo (n, x) $ a || b
    return memo
  | x - d >= (-size) = do
    a <- readArray memo (n-1, x-d)
    writeArray memo (n, x) a
    return memo
  |  x + d <= size = do
    b <- readArray memo (n-1, x+d)
    writeArray memo (n, x) b
    return memo
  | otherwise = do
    return memo
