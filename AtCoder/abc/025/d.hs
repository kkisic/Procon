import Data.Array.IO
import Data.Bits
import Data.Int
import Data.List
import Control.Monad

type Arr32 = IOUArray Int Int32
type Arr = IOUArray Int Int

modN = 10^9+7 :: Int32
maxN = 2^25-1

main = do
  x <- concat . map (map read . words) . lines <$> getContents :: IO [Int]
  posA <- newArray (1, 25) $ negate 1 :: IO Arr
  position posA x 0
  decided <- newArray (0, 25) 0 :: IO Arr
  writeArray decided 0 0
  pos <- getElems posA
  makeDec decided pos 1
  memo <- newArray (0, maxN) $ negate 1 :: IO Arr32
  writeArray memo 0 1
  ans <- dp decided posA memo maxN
  print ans

position :: Arr -> [Int] -> Int -> IO ()
position arr []     _ = return ()
position arr (0:xs) i = position arr xs $ i + 1
position arr (x:xs) i = do
  writeArray arr x i
  position arr xs $ i + 1

dp :: Arr -> Arr -> Arr32 -> Int -> IO Int32 
dp  decided pos memo s = do
  p <- readArray memo s
  if p == negate 1
    then dp' decided pos memo s
    else return p

dp' :: Arr -> Arr -> Arr32 -> Int -> IO Int32
dp' decided pos memo i = do
  let n = popCount i
  k <- readArray pos n
  d <- readArray decided n
  if k == negate 1
    then do --free
      if d .&. i == d
        then do
          let able = place (xor i d) 0
          p' <- mapM (pattern decided pos i memo) able
          let p = foldSumMod p'
          writeArray memo i p
          return p
        else do
          return 0
    else do --fixed
      if shiftR i k .&. 1 == 1
        then do
          let pre = i .&. (complement $ shiftL 1 k)
          if judge pre k
            then do
              p <- dp decided pos memo pre
              writeArray memo i p
              return p
            else do
              return 0
        else do
          return 0

--置く場所の候補
place :: Int -> Int -> [Int]
place _ 25 = []
place n i
  | shiftR n i .&. 1 == 1 = i : (place n $ i+1)
  | otherwise = place n $ i+1

--現在状態n, i番目が今置く場所 の時のパターン数
-- 0 <= i <= 24
pattern :: Arr -> Arr -> Int -> Arr32 -> Int -> IO Int32
pattern decided pos n memo i = do
  let pre = n .&. (complement $ shiftL 1 i)
  if judge pre i
    then dp decided pos memo pre
    else return 0

--前状態n, i番目に置けるか否か
-- 0 <= i <= 24
-- (0, 0) <= (ro, co) <= (4, 4)
judge :: Int -> Int -> Bool
judge n i =
  let ro = div i 5
      co = mod i 5
      l = if 0 <= co-1 && co-1 <= 4
            then shiftR n (i-1) .&. 1
            else 2
      r = if 0 <= co+1 && co+1 <= 4
            then shiftR n (i+1) .&. 1
            else 2
      u = if 0 <= ro-1 && ro-1 <= 4
            then shiftR n (i-5) .&. 1
            else 2
      d = if 0 <= ro+1 && ro+1 <= 4
            then shiftR n (i+5) .&. 1
            else 2
      lr = if l == 2 || r == 2 then True else l == r
      ud = if u == 2 || d == 2 then True else u == d
  in lr && ud

foldSumMod :: [Int32] -> Int32
foldSumMod xs = foldl1 (\x y -> flip mod modN $ x + y) xs

makeDec :: Arr -> [Int] -> Int -> IO ()
makeDec arr []     _ = return ()
makeDec arr (-1:ps) i = do
  x <- readArray arr $ i-1
  writeArray arr i x
  makeDec arr ps $ i + 1
makeDec arr (p:ps) i = do
  x <- readArray arr $ i-1
  writeArray arr i $ x .|. shiftL 1 p
  makeDec arr ps $ i + 1
