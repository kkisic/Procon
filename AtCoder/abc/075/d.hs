import Data.List
import Data.Array.Unboxed

main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  [x, y] <- transpose . map (map read . words) . lines <$> getContents :: IO [[Int]]
  let points = zip x y
      index = [(i, j) | i <- [1..n], j <- [1..n], i + k - 1 <= j]
      xArray = listArray (1, n) $ sort x :: UArray Int Int
      yArray = listArray (1, n) $ sort y :: UArray Int Int
  print . minimum . filter (/=(-1)) . concat $ map (loopX points k xArray yArray index) index

loopX :: [(Int, Int)] -> Int -> UArray Int Int -> UArray Int Int -> [(Int, Int)] -> (Int, Int) -> [Integer]
loopX p k x y ys (xi, xj) = let l = x ! xi
                                r = x ! xj
                            in map (loopY p k l r y) ys

loopY :: [(Int, Int)] -> Int -> Int -> Int -> UArray Int Int -> (Int, Int) -> Integer
loopY p k l r y (yi, yj) = let t = y ! yi
                               b = y ! yj
                           in if count l r t b p >= k
                                then (*) (toInteger $ r - l) (toInteger $ b - t)
                                else -1

count :: Int -> Int -> Int -> Int -> [(Int, Int)] -> Int
count _ _ _ _ []     = 0
count l r t b ((x, y):s)
  | l <= x && x <= r && t <= y && y <= b = 1 + count l r t b s
  | otherwise                            = 0 + count l r t b s
