import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Bits
import Data.Array.IO
import Control.Monad

type BIT = IOUArray Int Int
type Memo = IOUArray Int Int

main = do
  n <- readLn :: IO Int
  box <- sortBy compareBox . map (\[x,y] -> (x, y)) <$> getInt2DListBC
  bit <- newArray (1, 10^5) 0 :: IO BIT
  memo <- newArray (1, n) 0 :: IO Memo
  solve memo bit box 1
  ans <- getElems memo
  print $ maximum ans

maxBIT :: BIT -> Int -> IO Int
maxBIT bit 0 = return 0
maxBIT bit i = do
  x <- readArray bit i
  y <- maxBIT bit $ i-(i.&.(negate i))
  return $ max x y

addBIT :: BIT -> (Int, Int) -> IO BIT
addBIT bit (i, x) = do
  m <- snd <$> getBounds bit
  if i > m
    then return bit
    else do
      y <- readArray bit i
      writeArray bit i $ max x y
      addBIT bit ((i+(i.&.(negate i))), x)

solve :: Memo -> BIT -> [(Int, Int)] -> Int -> IO BIT
solve memo bit [] i = return bit
solve memo bit ((w,h):ps) i = do
  m <- maxBIT bit $ w - 1
  writeArray memo i $ m+1
  addBIT bit (w, m+1)
  solve memo bit ps $ i + 1

compareBox :: (Int, Int) -> (Int, Int) -> Ordering
compareBox (w1, h1) (w2, h2) = if h1 == h2
                              then compare w2 w1
                              else compare h1 h2

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
