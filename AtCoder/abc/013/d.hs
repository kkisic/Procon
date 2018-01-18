import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Data.Bits
import Control.Monad

type Arr = IOUArray Int Int
type Arr2D = IOUArray (Int, Int) Int

maxLog = 31

main = do
  [n,m,d] <- map read . words <$> getLine :: IO [Int]
  a <- getIntListBC
  pos <- newListArray (1, n) [1..n] :: IO Arr
  foldM amida pos a
  a'' <- getElems pos
  let l = snd . unzip . sort $ zip a'' [1..n]
  table <- newArray ((1, 0), (n, maxLog-1)) 0 :: IO Arr2D
  initTable table l 1
  foldM (makeTable table n) pos [0..maxLog-2]
  ans <- newListArray (1, n) [1..n] :: IO Arr
  foldM (solve table n d) ans [0..maxLog-1]
  ans' <- getElems ans
  let l' = snd . unzip . sort $ zip ans' [1..n]
  putStr $ unlines . map show $ l'

solve :: Arr2D -> Int -> Int -> Arr -> Int -> IO Arr
solve table n i ans k = do
  if shiftR i k .&. 1 == 1
    then do
      ls <- getElems ans
      l <- getLot table k n 1
      update ans l ls
      return ans
    else return ans

update :: Arr -> [Int] -> [Int] -> IO ()
update _   []     []     = return ()
update pos (l:ls) (a:as) = do
  writeArray pos l a
  update pos ls as

initTable :: Arr2D -> [Int] -> Int -> IO ()
initTable table []     _ = return ()
initTable table (i:is) n = do
  writeArray table (n, 0) i
  initTable table is $ n+1

makeTable :: Arr2D -> Int -> Arr -> Int -> IO Arr
makeTable table n pos k = do
  pos' <- getElems pos
  l <- getLot table k n 1
  move pos l pos'
  p <- getElems pos
  let p' = snd . unzip . sort $ zip p [1..n]
  add p' 1
  return pos
  where move :: Arr -> [Int] -> [Int] -> IO ()
        move p []     []     = return ()
        move p (l:ls) (i:is) = do
          writeArray p l i
          move p ls is
        add :: [Int] -> Int -> IO ()
        add []     _ = return ()
        add (p:ps) i = do
          writeArray table (i, k+1) p
          add ps $ i+1

getLot :: Arr2D -> Int -> Int -> Int -> IO [Int]
getLot table k n i
  | n < i = return []
  | otherwise = do
    x <- readArray table (i, k)
    xs <- getLot table k n $ i+1
    return $ x : xs

amida :: Arr -> Int -> IO Arr
amida arr i = do
  x <- readArray arr i
  y <- readArray arr $ i+1
  writeArray arr i y
  writeArray arr (i+1) x
  return arr

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
