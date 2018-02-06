import Data.List
import Data.Array.Unboxed
import Debug.Trace
import Data.ByteString.Char8 as BC (words, getLine, readInt)
import Data.Maybe (fromJust)

main = do
  n <- fst . fromJust . BC.readInt <$> BC.getLine
  a <- sort . map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
  b <- sort . map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
  c <- sort . map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
  let arrA = listArray (0, n-1) a :: UArray Int Int
      arrC = listArray (0, n-1) c :: UArray Int Int
  print $ count arrA arrC b

count :: UArray Int Int -> UArray Int Int -> [Int] -> Int
count a c b = sum $ map (\x -> (lt a x) * (gt c x)) b

lt :: UArray Int Int -> Int -> Int
lt a b = (+1) $ upperBound b a

gt :: UArray Int Int -> Int -> Int
gt a b = ((+1) . snd . bounds $ a) - (lowerBound b a)

--[lb, ub) x未満のmax
upperBound :: Int -> UArray Int Int -> Int
upperBound x xs = innerUB (0-1) ((+1) . snd $ bounds xs) x xs

innerUB :: Int -> Int -> Int -> UArray Int Int -> Int
innerUB lb ub x xs
  | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                   in if (xs ! mid) < x then innerUB mid ub x xs
                                        else innerUB lb mid x xs
  | otherwise   = lb

--(lb, ub] xより大きいmin
lowerBound :: Int -> UArray Int Int -> Int
lowerBound x xs = innerLB (0-1) ((+1) . snd $ bounds xs) x xs

innerLB :: Int -> Int -> Int -> UArray Int Int -> Int
innerLB lb ub x xs
  | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                   in if (xs ! mid) > x then innerLB lb mid x xs
                                        else innerLB mid ub x xs
  | otherwise   = ub
