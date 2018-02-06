import qualified Data.ByteString.Char8 as BC
import Data.Array.IO
import Data.Maybe (fromJust)

type Arr = IOUArray Int Int

modN = 10^9+7

main = do
  [n,m] <- map read . words <$> getLine :: IO [Int]
  f <- getIntListBC
  dp <- newArray (0, 10^5+10) 0 :: IO Arr
  num <- newArray (1, m) 0 :: IO Arr
  ff <- newListArray (0, n-1) f :: IO Arr
  writeArray dp 0 1
  solve dp num 1 0 ff 0 n
  ans <- readArray dp n
  print ans

solve :: Arr -> Arr -> Int -> Int -> Arr -> Int -> Int -> IO ()
solve dp num sum now ff i n
  | i == n = return ()
  | otherwise = do
    f <- readArray ff i
    x <- readArray num f
    writeArray num f $ x + 1
    (sum', now') <- solve' num sum now f
    writeArray dp (i+1) sum'
    let sum'' = flip mod modN $ sum' + sum'
    solve dp num sum'' now' ff (i + 1) n
      where solve' :: Arr -> Int -> Int -> Int -> IO (Int, Int)
            solve' num sum now f = do
              n <- readArray num f
              if n > 1
                then do
                  f' <- readArray ff now
                  y <- readArray num f'
                  writeArray num f' $ y - 1
                  d <- readArray dp now
                  let s = flip mod modN $ modN + sum - d
                  solve' num s (now + 1) f
                else return (sum, now)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents
