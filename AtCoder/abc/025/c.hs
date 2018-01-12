import qualified Data.Map.Strict as MS
import qualified Data.IntMap as M
import Data.Array.Unboxed
import Data.Array.IO
import Data.List
import Data.Bits
import Data.Maybe (fromJust)
import Control.Monad

type Score = UArray (Int, Int) Int
type Board = MS.Map (Int, Int) Int
type Memo = M.IntMap Int

noScore = 10^5

main = do
  b1 <- map read . words <$> getLine :: IO [Int]
  b2 <- map read . words <$> getLine :: IO [Int]
  c1 <- map read . words <$> getLine :: IO [Int]
  c2 <- map read . words <$> getLine :: IO [Int]
  c3 <- map read . words <$> getLine :: IO [Int]
  let b = listArray ((1, 1), (3, 3)) (b1 ++ b2 ++ [0, 0, 0]) :: Score
      c = listArray ((1, 1), (3, 3)) (c1 ++ [0] ++ c2 ++ [0] ++ c3 ++ [0]) :: Score
      a = [0, 1]
      pattern = [[d,e,f,g,h,i,j,k,l] | d <- a, e <- a, f <- a, g <- a, h <- a, i <- a, j <- a, k <- a, l <- a, d+e+f+g+h+i+j+k+l == 5]
      memo = foldl (memoize b c) M.empty pattern
      ans = game True 0 MS.empty memo
      all = sum $ b1 ++ b2 ++ c1 ++ c2 ++ c3
  print ans
  print $ all - ans

game :: Bool -> Int -> Board -> Memo -> Int
game _      9     board memo =
  let bin = toBin board
  in fromJust $ M.lookup bin memo
game player depth board memo =
  let s = map (game' player depth board memo) [(i, j) | i <- [1..3], j <- [1..3]]
  in if player
    then maximum . filter (/=noScore) $ s
    else minimum . filter (/=noScore) $ s

game' :: Bool -> Int -> Board -> Memo -> (Int, Int) -> Int
game' player depth board memo (i, j) =
  let flag = MS.lookup (i, j) board
  in case flag of
       Nothing -> let board' = if player
                                 then MS.insert (i, j) 1 board
                                 else MS.insert (i, j) 0 board
                  in game (not player) (depth+1) board' memo
       _ -> noScore

toBin :: Board -> Int
toBin board = let b = snd . unzip . MS.toList $ board
              in toBin' b 0

toBin' :: [Int] -> Int -> Int
toBin' []        n = n
toBin' (x:xs)    n = toBin' xs $ (shiftL n 1) + x

memoize :: Score -> Score -> Memo -> [Int] -> Memo
memoize b c memo board =
  let score = evaluate b c board
      bin = toBin' board 0
  in M.insert bin score memo

evaluate :: Score -> Score -> [Int] -> Int
evaluate b c board =
  let board' = listArray ((1, 1), (3, 3)) board :: Score
      s = foldl (scoreB b board') 0 [(1, 1), (1, 2), (1, 3), (2, 1), (2, 2), (2, 3)]
  in foldl (scoreC c board') s [(1, 1), (1, 2), (2, 1), (2, 2), (3, 1), (3, 2)]

scoreB :: Score -> Score -> Int -> (Int, Int) -> Int
scoreB b board s (i, j) = do
  let point = b ! (i, j)
      x = board ! (i, j)
      y = board ! (i+1, j)
  if x == y
    then s + point
    else s

scoreC :: Score -> Score -> Int -> (Int, Int) -> Int
scoreC c board s (i, j) = do
  let point = c ! (i, j)
      x = board ! (i, j)
      y = board ! (i, j+1)
  if x == y
    then s + point
    else s
