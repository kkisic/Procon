import Data.Array.IO
import Control.Monad

type Memo = IOUArray Int Int

main = do
  n <- readLn :: IO Int
  table <- newArray (1, n) 0 :: IO Memo
  writeArray table 1 2
  prime table 1 n [i | i <- [3..n], odd i == True]
  pList <- filter (/=0) <$> getElems table
  count <- newArray (1, length pList) 0 :: IO Memo
  foldM (divisor pList 1) count [2..n]
  cList <- map (+1) . filter (/=0) <$> getElems count
  if n == 1 then print 1
            else print $ foldl1 (\x y -> mod (x * y) $ 10^9+7) cList

count :: [Int] -> Int -> Int
count nums n = length $ filter ((==0) . mod n) nums

prime :: Memo -> Int -> Int -> [Int] -> IO Memo
prime table pn n []     = return table
prime table pn n x@(i:is) = do
  if i^2 <= n
    then do
      writeArray table (pn+1) i
      let is' = filter ((/=0) . flip mod i) is
      prime table (pn+1) n is'
    else do
      let len = length x
          idx = [pn+1..pn+len]
      prime' $ zip idx x
      return table
            where prime' :: [(Int, Int)] -> IO Memo
                  prime' [] = return table
                  prime' ((i, n):ss) = do
                    writeArray table i n
                    prime' ss

divisor :: [Int] -> Int -> Memo -> Int -> IO Memo
divisor [] _ memo _ = return memo
divisor _  _ memo 1 = return memo
divisor p  i memo n
  | mod n (p !! (i-1)) == 0 = do
    c <- readArray memo i
    writeArray memo i $ c + 1
    divisor p 1 memo $ div n (p !! (i-1))
  | otherwise    = divisor p (i+1) memo n
