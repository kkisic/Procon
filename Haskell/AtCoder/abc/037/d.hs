import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Memo2D = IOUArray (Int, Int) Int

modN = 10^9+7

main = do
  [h,w] <- map read . words <$> getLine :: IO [Int]
  a <- concat <$> getInt2DListBC
  area <- newListArray ((1, 1), (h, w)) a :: IO Memo2D
  ans <- newArray ((1, 1), (h, w)) (-1) :: IO Memo2D
  foldM (solve h w area) ans [1..h]
  count <- getElems ans
  let ans = foldl1 (\x y -> flip mod modN $ x + y) count
  print ans

solve :: Int -> Int -> Memo2D -> Memo2D -> Int -> IO Memo2D
solve h w area memo i = do
  foldM (dp h w i area) memo [1..w]

dp :: Int -> Int -> Int -> Memo2D -> Memo2D -> Int -> IO Memo2D
dp h w i area memo j = do
  count <- mapM dp' [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]
  let ans = foldl (\x y -> flip mod modN $ x + y) 1 count
  writeArray memo (i, j) ans
  return memo
  where dp' :: (Int, Int) -> IO Int
        dp' (i', j')
          | 1 <= i' && i' <= h && 1 <= j' && j' <= w = do
            x <- readArray memo (i', j')
            p <- readArray area (i, j)
            d <- readArray area (i', j')
            if p < d
              then do
                if x == (-1)
                  then do
                    dp h w i' area memo j'
                    y <- readArray memo (i', j')
                    return y
                  else return x
              else return 0
          | otherwise = return 0

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
