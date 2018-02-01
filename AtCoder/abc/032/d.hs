import qualified Data.ByteString.Char8 as BC
import Data.Array.IO
import Data.Array.Unboxed
import Data.Maybe (fromJust)
import Data.Bits
import Data.List
import Control.Monad

type Arr = IOUArray Int Int
type IArr = UArray Int Int

main = do
  [n,w] <- map read . words <$> getLine :: IO [Int]
  item <- map (\[x,y] -> (x,y)) <$> getInt2DListBC
  let vMax = maximum $ map fst item
      wMax = maximum $ map snd item
  print =<< solve n w vMax wMax item

solve :: Int -> Int -> Int -> Int -> [(Int, Int)] -> IO Int
solve n w vMax wMax item
  | n <= 30 = do
    let n1 = div n 2
        s1 = take n1 item
        s2 = drop n1 item
        p1 = remove . sortBy compareItem $ allPattern n1 s1
        p2 = allPattern (n-n1) s2
        value = listArray (1, length p1) $ fst . unzip $ p1 :: IArr
        weight = listArray (1, length p1) $ snd . unzip $ p1 :: IArr
    return $ foldl' (solve1 value weight (length p1) w) 0 p2
  | wMax <= 1000 = do
    arr <- newArray (0, 2*10^5) 0 :: IO Arr
    foldM dp arr item
    readArray arr $ min w $ 2*10^5
  | vMax <= 1000 = do
    arr <- newArray (0, 2*10^5) inf :: IO Arr
    writeArray arr 0 0
    foldM dp2 arr item
    l <- getElems arr
    return $ last . findIndices (<=w) $ l

solve1 :: IArr -> IArr -> Int -> Int -> Int -> (Int, Int) -> Int
solve1 value weight n capacity bestV (v, w)
  | capacity < w = bestV
  | otherwise =
  let iv = upperBound (judge weight $ capacity-w) 1 (n + 1)
  in max bestV $ (value ! iv) + v

--[lb, ub)
upperBound :: (Int -> Bool) -> Int -> Int -> Int
upperBound f lb ub
  | ub - lb == 1 = lb
  | otherwise = do
    let mid = div (lb + ub) 2
    if f mid
      then upperBound f mid ub
      else upperBound f lb mid

judge :: IArr -> Int -> Int -> Bool
judge arr x m = (arr ! m) <= x

allPattern :: Int -> [(Int, Int)] -> [(Int, Int)]
allPattern n item =
  let set = [0..2^n-1]
      v = listArray (1, n) $ fst . unzip $ item :: IArr
      w = listArray (1, n) $ snd . unzip $ item :: IArr
  in allPattern' v w set

allPattern' :: IArr -> IArr -> [Int] -> [(Int, Int)]
allPattern' _     _      []     = []
allPattern' value weight (s:ss) =
  let v = sumSet value s 1
      w = sumSet weight s 1
  in (v, w) : (allPattern' value weight ss)

sumSet :: IArr -> Int -> Int -> Int
sumSet arr set i
  | shiftR set (i-1) == 0 = 0
  | otherwise =
  if shiftR set (i-1) .&. 1 == 1
    then (arr ! i) + sumSet arr set (i+1)
    else sumSet arr set $ i+1

remove :: [(Int, Int)] -> [(Int, Int)]
remove (i:[]) = [i]
remove ((v1, w1):(v2, w2):s)
  | w1 == w2 = remove $ (v2, w2):s
  | v1 < v2 = (v1, w1) : (remove $ (v2, w2):s)
  | otherwise = (v1, w1) : (remove s)

compareItem :: (Int, Int) -> (Int, Int) -> Ordering
compareItem (v1, w1) (v2, w2) =
  if w1 == w2
    then compare v1 v2
    else compare w1 w2

idx = reverse [0..2*10^5]

dp :: Arr -> (Int, Int) -> IO Arr
dp arr (v, w) = do
  foldM (dp' (v, w)) arr idx
  return arr

dp' :: (Int, Int) -> Arr -> Int -> IO Arr
dp' (v, w) arr capacity = do
  if w <= capacity
    then do
      v1 <- readArray arr capacity
      v2 <- readArray arr $ capacity - w
      writeArray arr capacity $ max v1 $ v2 + v
      return arr
    else do
      return arr

inf = 10^10

dp2 :: Arr -> (Int, Int) -> IO Arr
dp2 arr (v, w) = do
  foldM (dp2' (v, w)) arr idx
  return arr

dp2' :: (Int, Int) -> Arr -> Int -> IO Arr
dp2' (v, w) arr capacity = do
  if v <= capacity
    then do
      w1 <- readArray arr capacity
      w2 <- readArray arr $ capacity - v
      writeArray arr capacity $ min w1 $ w2 + w
      return arr
    else do
      return arr

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
