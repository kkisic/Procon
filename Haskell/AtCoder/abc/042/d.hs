import Data.Array.IO
import Data.List
import Control.Monad

type Table = IOUArray Int Int

modN :: Int
modN = 10^9+7

main = do
  [h,w,a,b] <- map read . words <$> getLine :: IO [Int]
  let h' = h - 1
      w' = w - 1
      a' = a - 1
      b' = b - 1
      n = h' + w'
  table <- newArray (0, n+1) 0 :: IO Table
  factTable <- newArray (0, n) 0 :: IO Table
  foldM factT factTable [0..n]
  makeTable table n n
  let path = [b..w']
  ans <- foldl1 (\x y -> flip mod modN $ x + y) <$> mapM (solve table factTable a' w' (h-a-1)) path
  print ans

solve :: Table -> Table -> Int -> Int -> Int -> Int -> IO Int
solve table factTable a w l i = do
  cn1 <- readArray factTable $ l+i
  cn2 <- readArray factTable $ a+w-i
  x <- comb table cn1 (l+i) i
  y <- comb table cn2 (a+w-i) a
  return $ flip mod modN $ x * y

factT :: Table -> Int -> IO Table
factT table 0 = do
  writeArray table 0 1
  return table
factT table n = do
  pre <- readArray table $ n-1
  writeArray table n $ flip mod modN $ pre * n
  return table

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
