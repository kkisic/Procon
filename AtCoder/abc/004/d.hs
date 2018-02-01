main = do
  [r,g,b] <- map read . words <$> getLine :: IO [Int]
  let gp = [(l, l+g-1) | l <- [-1000..700]]
      ans = minimum $ map (solve r b) gp
  print ans

solve :: Int -> Int -> (Int, Int) -> Int
solve red blue (l, r) =
  let rr = (-101) + div (red+1) 2
      bl = 101 - div (blue+1) 2
  in solve' red blue rr bl (l, r)

solve' :: Int -> Int -> Int -> Int -> (Int, Int) -> Int
solve' red blue rr bl (l, r)
  | l > rr && r < bl =
  (moveCount l r) + (moveCount (rr-red+101) $ rr+100) + (moveCount (bl-100) $ bl+blue-101)
  | l > rr =
  (moveCount l r) + (moveCount (rr-red+101) $ rr+100) + (moveCount (r+1-100) $ r+1+blue-101)
  | r < bl =
  (moveCount l r) + (moveCount (l-1-red+101) (l-1+100)) + (moveCount (bl-100) $ bl+blue-101)
  | otherwise =
  (moveCount l r) + (moveCount (l-1-red+101) (l-1+100)) + (moveCount (r+1-100) $ r+1+blue-101)

moveCount :: Int -> Int -> Int
moveCount left right
  | left <= 0 && 0 <= right =
  sum [1..abs left] + sum [1..right]
  | right <= 0 =
  sum [1..abs left] - sum [1..(abs right) - 1]
  | otherwise =
  sum [1..right] - sum [1..left-1]
