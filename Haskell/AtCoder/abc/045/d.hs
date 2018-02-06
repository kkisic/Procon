import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Array.IO
import Data.Maybe (fromJust)
import Data.List
import Control.Monad

main = do
  [h,w,n] <- map read . words <$> getLine :: IO [Int]
  painted <- getInt2DListBC
  let sub = map (\x -> (head x, length x)) . group . sort . map length . group . sort . concat $ map (solve h w) painted
  memo <- newArray (1, 9) 0 :: IO (IOUArray Int Int)
  foldM count memo sub
  ans <- getElems memo
  let zero = (h-2)*(w-2) - (sum ans)
  print zero
  putStr $ unlines . map show $ ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

solve :: Int -> Int -> [Int] -> [(Int, Int)]
solve h w [x, y] = [(i, j) | i <- [x-1..x+1], j <- [y-1..y+1], 2 <= i, i <= h-1, 2 <= j, j <= w-1]

count :: IOUArray Int Int -> (Int, Int) -> IO (IOUArray Int Int)
count memo (i, c) = do
  writeArray memo i c
  return memo
