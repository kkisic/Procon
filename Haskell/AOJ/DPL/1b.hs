import Data.Array.IO

type Value = Int
type Weight = Int
type Item = (Weight, Value)
type ItemList = [Item]
type Capacity = Int

main :: IO ()
main = do
  input <- getContents
  let nums = map ((\x -> (last x, head x)) . map (read :: String -> Int) . words) . lines $ input
      capacity = fst . head $ nums
      items = tail nums
  memo <- newArray ((0, 0), (capacity, length items)) (0 - 1) :: IO (IOUArray (Int, Int) Int)
  dp (capacity, items) memo
  putStrLn . show . last =<< getElems memo

memoize :: (Capacity, ItemList) -> IOUArray (Int, Int) Int -> IO Int
memoize (c, i) t = do
  v <- readArray t (c, length i)
  if v < 0
    then do
      dp (c, i) t
      return =<< readArray t (c, length i)
    else return v

dp :: (Capacity, ItemList) -> IOUArray (Int, Int) Int -> IO (IOUArray (Int, Int) Int)
dp (c, []) t = do
  writeArray t (c, 0) 0
  return t
dp (c, as@(i:is)) t
  | c < fst i = do
    v <- memoize (c, is) t
    writeArray t (c, length as) v
    return t
  | otherwise = do
    x <- memoize (c, is) t
    y <- memoize (c - fst i, is) t
    writeArray t (c, length as) (max x $ y + snd i)
    return t
