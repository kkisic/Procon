import Data.List
import Data.Array.IO
import Control.Monad
import Data.Char

main = do
  [h, w] <- map read . words <$> getLine :: IO [Int]
  input <- concat . map toMineNum . lines <$> getContents :: IO [Int]
  area <- newListArray ((1, 1), (h, w)) input :: IO (IOUArray (Int, Int) Int)
  mine <- newArray ((1, 1), (h, w)) 0 :: IO (IOUArray (Int, Int) Int)
  areaList <- getElems area
  mine' <- foldM (repeatAddMine area (h, w)) mine [(i, j) | i <- [1..h], j <- [1..w]]
  mineList <- getElems mine'
  let ans = unlines . toString w $ zipWith (\x y -> if x == 1 then '#' else intToDigit y) areaList mineList
  putStr ans

toString :: Int -> String -> [String]
toString _ [] = []
toString w s = (take w s) : (toString w $ drop w s)

toMineNum :: String -> [Int]
toMineNum []  = []
toMineNum (x:xs)
  | x == '.'  = 0:toMineNum xs
  | otherwise = 1:toMineNum xs

addMine :: IOUArray (Int, Int) Int -> (Int, Int) -> Int -> (Int, Int) -> IO Int
addMine area (h, w) n (x, y)
  | 1 <= x && x <= h && 1 <= y && y <= w = do
    m <- readArray area (x, y)
    return $ m + n
  | otherwise = return n

repeatAddMine :: IOUArray (Int, Int) Int -> (Int, Int) -> IOUArray (Int, Int) Int -> (Int, Int) -> IO (IOUArray (Int, Int) Int)
repeatAddMine area (h, w) mine (x, y) = do
  n <- foldM (addMine area (h, w)) 0 [(i, j) | i <- [x-1, x, x+1], j <- [y-1, y, y+1], (i, j) /= (x, y)]
  writeArray mine (x, y) n
  return mine
