import qualified Data.ByteString.Char8 as BC
import qualified Data.Map.Strict as MS
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Array.IO
import Data.List
import Control.Monad

type Arr = IOUArray Int Int
type Pos = MS.Map (Int, Int) Bool

main = do
  [r,c,k] <- map read . words <$> getLine :: IO [Int]
  n <- readLn :: IO Int
  candy <- getInt2DListBC
  arrR <- newArray (1, r) 0 :: IO Arr
  arrC <- newArray (1, c) 0 :: IO Arr
  foldM countR arrR candy
  foldM countC arrC candy
  row <- map (\x -> (head x, length x)) . group . sort <$> getElems arrR
  column <- map (\x -> (head x, length x)) . group . sort <$> getElems arrC
  let pos = foldl setPos MS.empty candy
      row' = M.fromList row
      column' = M.fromList column
      ans1 = solve1 row' column' k 0
  ans2 <- mapM (solve2 arrR arrC) candy
  let kk = length . elemIndices k $ ans2
      kk1 = length . elemIndices (k+1) $ ans2
  print $ ans1 - kk + kk1

solve1 :: M.IntMap Int -> M.IntMap Int -> Int -> Int -> Int
solve1 row column k i
  | k < i     = 0
  | otherwise =
  let r = M.lookup i row
      c = M.lookup (k-i) column
      x = if r == Nothing
            then 0
            else fromJust r
      y = if c == Nothing
            then 0
            else (*x) $ fromJust c
  in y + (solve1 row column k $ i + 1)

solve2 :: Arr -> Arr -> [Int] -> IO Int
solve2 row column [r,c] = do
  x <- readArray row r
  y <- readArray column c
  return $ x + y

countR :: Arr -> [Int] -> IO Arr
countR arr [r, _] = do
  x <- readArray arr r
  writeArray arr r $ x + 1
  return arr

countC :: Arr -> [Int] -> IO Arr
countC arr [_, c] = do
  x <- readArray arr c
  writeArray arr c $ x + 1
  return arr

setPos :: Pos -> [Int] -> Pos
setPos pos [r, c] = MS.insert (r, c) True pos

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

