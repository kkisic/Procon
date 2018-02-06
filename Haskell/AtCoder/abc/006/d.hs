import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO

type Arr = IOUArray Int Int

main = do
  n <- readLn :: IO Int
  c <- getIntListBC
  l <- newArray (0, n-1) 0 :: IO Arr
  a <- newListArray (0, n-1) c :: IO Arr
  ans <- lis l a n
  print $ n - ans

lis :: Arr -> Arr -> Int -> IO Int
lis l a n = do
  v <- readArray a 0
  writeArray l 0 v
  lis' 1 1
  where lis' :: Int -> Int -> IO Int
        lis' len i
          | i >= n = return len
          | otherwise = do
            x <- readArray l $ len-1
            y <- readArray a i
            if x < y
              then do
                writeArray l len y
                lis' (len+1) $ i+1
              else do
                j <- lowerBound (judge l y) (-1) (len-1)
                writeArray l j y
                lis' len $ i+1

judge :: Arr -> Int -> Int -> IO Bool
judge arr v x = do
  a <- readArray arr x
  return $ a >= v

--(lb, ub]
lowerBound :: (Int -> IO Bool) -> Int -> Int -> IO Int
lowerBound f lb ub
  | ub - lb == 1 = return ub
  | otherwise = do
    let mid = div (lb + ub) 2
    flag <- f mid
    if flag
      then lowerBound f lb mid
      else lowerBound f mid ub

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents
