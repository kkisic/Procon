import Data.Array.IO
import Data.Maybe (fromJust)

type Width = Int
type Value = Int
type Picture = (Width, Value)
type PicList = [Picture]
type Arr = IOUArray (Width, Int, Int) Int

main = do
  w <- readLn :: IO Int
  [n,k] <- map read . words <$> getLine :: IO [Int]
  pic <- map ((\[x,y] -> (read x, read y)) . words) . lines <$> getContents :: IO [Picture]
  memo <- newArray ((0, 0, 0), (w, k, length pic)) (0 - 1) :: IO Arr
  dp (w, k, pic) memo
  v <- readArray memo (w, k, length pic)
  print v

dp :: (Width, Int, PicList) -> Arr -> IO Arr
dp (w, 0, p)        memo = do
  writeArray memo (w, 0, length p) 0
  return memo
dp (w, k, [])       memo = do
  writeArray memo (w, k, 0) 0
  return memo
dp (w, k, p@(i:is)) memo
  | w < fst i = do
    v <- readDP (w, k, is) memo
    writeArray memo (w, k, length p) v
    return memo
  | otherwise = do
    x <- readDP (w, k, is) memo
    y <- readDP (w - fst i, k-1, is) memo
    writeArray memo (w, k, length p) $ max x $ y + snd i
    return memo

readDP :: (Width, Int, PicList) -> Arr -> IO Value
readDP (w, k, p) memo = do
  v <- readArray memo (w, k, length p)
  if v < 0
    then do
      dp (w, k, p) memo
      return =<< readArray memo (w, k, length p)
    else return v
