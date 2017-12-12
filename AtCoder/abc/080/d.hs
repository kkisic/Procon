import Data.List
import Data.Array.IO

main = do
  getLine
  chan <- map cut . foldl1 connect . map (:[]) . sortBy compareC . map (readC . words) . lines <$> getContents
  let rr = newArray (0,200000) 0 :: IO (IOUArray Int Int)
  ss <- getElems =<< foldl reserveS rr chan
  tt <- getElems =<< foldl reserveT rr chan
  let table = zip ss tt
  putStrLn . show . maximum $ count 0 table

readC :: [String] -> (Int, Int, Int)
readC s = ((read :: String -> Int) (s !! 0), (read :: String -> Int) (s !! 1), (read :: String -> Int) (s !! 2))

compareC :: (Int, Int, Int) -> (Int, Int, Int) -> Ordering
compareC (s1, t1, c1) (s2, t2, c2) = if c1 /= c2 then compare c1 c2
                                                 else compare s1 s2

equalC :: (Int, Int, Int) -> (Int, Int, Int) -> Bool
equalC (_, _, c1) (_, _, c2) = c1 == c2

isConnect :: (Int, Int, Int) -> (Int, Int, Int) -> Bool
isConnect (_, t, _) (s, _, _) = t == s

connect :: [(Int, Int, Int)] -> [(Int, Int, Int)] -> [(Int, Int, Int)]
connect s@(x:xs) (y:_) = if equalC x y && isConnect x y
                    then (connect' x y):xs
                    else y:s

connect' :: (Int, Int, Int) -> (Int, Int, Int) -> (Int, Int, Int)
connect' (s, _, c) (_, t, _) = (s, t, c)

cut :: (Int, Int, Int) -> (Int, Int)
cut (s, t, _) = (s * 2 - 1, t * 2)

reserveS :: IO(IOUArray Int Int) -> (Int, Int) -> IO (IOUArray Int Int)
reserveS a (s, _) = f a s

reserveT :: IO(IOUArray Int Int) -> (Int, Int) -> IO (IOUArray Int Int)
reserveT a (_, t) = f a t

f :: IO (IOUArray Int Int) -> Int -> IO (IOUArray Int Int)
f a t = do
  aa <- a
  n <- readArray aa t
  writeArray aa t (n + 1)
  return aa

count :: Int -> [(Int, Int)] -> [Int]
count n []     = []
count n (x:xs) = let nn = n + (fst x - snd x)
                    in nn:count nn xs
