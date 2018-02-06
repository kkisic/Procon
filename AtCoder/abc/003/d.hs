import Data.Array.IO
import Data.List

main = do
  [r,c] <- map read . words <$> getLine :: IO [Int]
  [x,y] <- map read . words <$> getLine :: IO [Int]
  [d,l] <- map read . words <$> getLine :: IO [Int]
  ans <- solve r c x y d l
  print ans

solve :: Int -> Int -> Int -> Int -> Int -> Int -> IO Int
solve r c x y d l = do
  table <- newArray (0, x*y) 0 :: IO Table
  makeTable table (x*y) (x*y)
  let rc = (r-x+1) * (c-y+1)
  all <- count table x y d l
  u <- count table (x-1) y d l
  ll <- count table x (y-1) d l
  ul <- count table (x-1) (y-1) d l
  ud <- count table (x-2) y d l
  lr <- count table x (y-2) d l
  udl <- count table (x-2) (y-1) d l
  ulr <- count table (x-1) (y-2) d l
  udlr <- count table (x-2) (y-2) d l
  let a = foldl1' (\s t -> flip mod modN $ s + t) [all, ul, ul, ul, ul, ud, lr, udlr]
      b = foldl1' (\s t -> flip mod modN $ s + t) [u, u, ll, ll, udl, udl, ulr, ulr]
      ab = flip mod modN $ modN + a - b
  return $ flip mod modN $ rc * ab

count :: Table -> Int -> Int -> Int -> Int -> IO Int
count table x y d l
  | x*y < d + l || x < 0 || y < 0 = return 0
  | otherwise = do
    a <- comb table (fact $ x*y) (x*y) d
    b <- comb table (fact $ x*y-d) (x*y-d) l
    return $ flip mod modN $ a * b

type Table = IOUArray Int Int

modN :: Int
modN = 10^9+7

--x^n (mod modN)
(|^) :: Int -> Int -> Int
(|^) x n
  | n == 0    = 1
  | even n    = (mod (x * x) modN) |^ (n `div` 2)
  | otherwise = (flip mod modN) . (*x) $ x |^ (n - 1)

--x! (mod modN)
fact :: Int -> Int
fact n
  | n == 0    = 1
  | otherwise = (flip mod modN) . (*n) $ fact (n-1)

--nCk cn:n!
comb :: Table -> Int -> Int -> Int -> IO Int
comb memo cn n k
  |n >= k = do
    ik <- readArray memo k
    ink <- readArray memo $ n - k
    let tmp = flip mod modN $ cn * ik
        ans = flip mod modN $ tmp * ink
    return ans
  | otherwise = return 0

makeTable :: Table -> Int -> Int -> IO Table
makeTable table n (-1) = return table
makeTable table n i
  | n == i = do
    writeArray table i $ (fact n) |^ (10^9+5)
    makeTable table i $ i-1
  | otherwise = do
    ie <- readArray table (i+1)
    writeArray table i $ flip mod modN $ ie * (i+1)
    makeTable table i $ i-1
