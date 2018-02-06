import Data.Array.IO

main = do
  [w,h] <- map read . words <$> getLine :: IO [Int]
  table <- newArray (0, w+h-2) 0 :: IO Table
  makeTable table (w+h-2) (w+h-2)
  ans <- comb table (fact $ w+h-2) (w+h-2) (w-1)
  print ans

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
