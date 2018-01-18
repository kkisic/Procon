import Data.Array.Unboxed

main :: IO ()
main = return ()

--[lb, ub) x未満のmax
upperBound :: Int -> UArray Int Int -> Int
upperBound x xs = innerUB (0-1) ((+1) . snd $ bounds xs)
  where innerUB lb ub
          | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                          in if (xs ! mid) < x
                               then innerUB mid ub
                               else innerUB lb mid
          | otherwise   = lb

--(lb, ub] xより大きいmin
lowerBound :: Int -> UArray Int Int -> Int
lowerBound x xs = innerLB (0-1) ((+1) . snd $ bounds xs)
  where innerLB lb ub
          | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                          in if (xs ! mid) > x
                               then innerLB lb mid
                               else innerLB mid ub
          | otherwise   = ub

--[lb, ub)
upperBound :: (Int -> IO Bool) -> Int -> Int -> IO Int
upperBound f lb ub
  | ub - lb == 1 = return ub
  | otherwise = do
    let mid = div (lb + ub) 2
    flag <- f mid
    if flag
      then upperBound f mid ub
      else upperBound f lb mid

--(lb, ub]
lowerBound :: (Int -> IO Bool) -> Int -> Int -> IO Int
lowerBound f lb ub
  | ub - lb == 1 = return ub
  | otherwise = do
    let mid = div (lb + ub) 2
    flag <- f mid
    if flag
      then lowerBound f lb mid
      else lowerBound f mid ub
