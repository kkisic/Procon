import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

main :: IO ()
main = return ()

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

--2進数へ基数変換
int2bin :: Int -> [Int]
int2bin 0 = []
int2bin n = n `mod` 2 : int2bin (n `div` 2)

bitCount :: Int -> Int
bitCount 0 = 0
bitCount n = n `mod` 2 + bitCount (n `div` 2)

repeatMemo :: IOUArray Int Int -> [Int] -> IO (IOUArray Int Int)
repeatMemo memo (a:b:_) = do
  return =<< foldM memoize memo [a..b]

memoize :: IOUArray Int Int -> Int -> IO (IOUArray Int Int)
memoize memo x = do
  n <- readArray memo x
  writeArray memo x (n+1)
  return memo

repeatMemoize :: IOUArray Int Int -> (Int, Int) -> IO (IOUArray Int Int)
repeatMemoize memo (i, j) = do
  return =<< foldM memoize memo [i..j]


--2次元リスト(concat済)出力
printList2D :: Int -> [Int] -> IO ()
printList2D _ []   = return ()
printList2D n list = do
  print $ take n list
  printList2D n $ drop n list



--素数表 pn:登録済の素数の個数 n:表の上限 x:判定対象のリスト
--ex) prime table 1 n [i | i <- [3..n], odd i == True]
prime :: Table -> Int -> Int -> [Int] -> IO Table
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
            where prime' :: [(Int, Int)] -> IO Table
                  prime' [] = return table
                  prime' ((i, n):ss) = do
                    writeArray table i n
                    prime' ss


--逆元表
type Table = IOUArray Int Int

modN :: Int
modN = 10^9+7

--x^n (mod modN)
(|^) :: Int -> Int -> Int
(|^) x n
  | n == 0    = 1
  | even n    = (mod (x * x) modN) |^ (n `div` 2)
  | otherwise = (flip mod modN) . (*x) $ x |^ (n - 1)

--x! (mod modN)
fact :: Int -> Int
fact n
  | n == 0    = 1
  | otherwise = (flip mod modN) . (*n) $ fact (n-1)

--nCk cn:n!
comb :: Table -> Int -> Int -> Int -> IO Int
comb memo cn n k
  |n >= k = do
    ik <- readArray memo k
    ink <- readArray memo $ n - k
    let tmp = flip mod modN $ cn * ik
        ans = flip mod modN $ tmp * ink
    return ans
  | otherwise = return 0

makeTable :: Table -> Int -> Int -> IO Table
makeTable table n (-1) = return table
makeTable table n i
  | n == i = do
    writeArray table i $ (fact n) |^ (10^9+5)
    makeTable table i $ i-1
  | otherwise = do
    ie <- readArray table (i+1)
    writeArray table i $ flip mod modN $ ie * (i+1)
    makeTable table i $ i-1



--尺取り法
inchWorm :: Int -> Int -> S.Seq Int -> [Int] -> [Int]
inchWorm _     _   _   []     = []
inchWorm limit sum seq (n:ns)
  | S.length seq == 0 && limit >= sum + n
    = (sum+n) : (inchWorm limit (sum+n) (S.empty S.|> n) ns)
  | S.length seq == 0 = inchWorm limit sum S.empty ns
  | limit >= sum + n  = (sum+n) : (inchWorm limit (sum+n) (seq S.|> n) ns)
  | otherwise         = inchWorm limit ((-) sum (fst . dequeue $ seq)) (S.drop 1 seq) (n:ns)

dequeue :: S.Seq a -> (a, S.Seq a)
dequeue que = case S.viewl que of
                S.EmptyL -> error "Empty Queue"
                x S.:< xs -> (x, xs)



--二分法 n:反復上限, [l, r],
bisection :: Int -> Double -> Double -> [[Double]] -> Double
bisection 100 l r input = l
bisection n   l r input
  | l == r = l
  | otherwise = let m = (l + r) / 2
                    b = f k m input
                in if b
                     then bisection (n+1) m r input
                     else bisection (n+1) l m input
    where f = undifined

--bin sort
bsort :: Int -> [Int] -> IO [Int]
bsort n x = do
  arr <- newArray (0, n) 0 :: IO Arr
  foldM bsort' arr x
  l <- getElems arr
  sorted <- make arr [0..n]
  return sorted
    where bsort' :: Arr -> Int -> IO Arr
          bsort' arr a = do
            c <- readArray arr a
            writeArray arr a $ c+1
            return arr
          make :: Arr -> [Int] -> IO [Int]
          make _   []    = return []
          make arr (i:is)
            | otherwise = do
              c <- readArray arr i
              next <- make arr is
              return $ (replicate c i) ++ next

--約数
divisor :: Int -> [Int]
divisor n = divisor' [1..(floor . sqrt . realToFrac $ n)]
  where divisor' [] = []
        divisor' (i:is) = if mod n i == 0
                            then if div n i /= i
                                   then i : (div n i) : (divisor' is)
                                   else i : (divisor' is)
                            else divisor' is

--素因数
factorization :: Int -> [Int]
factorization n = f n [2..(floor . sqrt . realToFrac $ n)]
  where f n' [] = if n' == 1
                    then []
                    else [n']
        f n' (i:is) = if mod n' i == 0
                       then i : (f (g n' i) is)
                       else f n' is
        g n'' i
          | mod n'' i == 0 = g (div n'' i) i
          | otherwise      = n''
