import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  let ra = reverse a
      sumf = sum $ take n a
      suml = sum $ take n ra
      fHalf = foldl (flip push) Empty $ take n a
      lHalf = foldl (flip push) Empty $ map (negate) $ take n ra
      first = ((:)sumf) . solveMax fHalf sumf (fromJust $ pop fHalf) $ take n $ drop n a
      latter = ((:)suml) . solveMin lHalf suml (fromJust $ pop lHalf) $ take n $ drop n ra
      ans = zipWith (-) first $ reverse latter
  print $ maximum ans
  return ()

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

solveMax :: SkewHeap Int -> Int -> Int -> [Int] -> [Int]
solveMax _    _   _ []     = []
solveMax heap sum m (a:as) =
  let heap' = if a > m
                then push a $ deleteMin heap
                else heap
      sum' = if a > m then sum + a - m
                      else sum
      m' = if a > m then fromJust $ pop heap'
                    else m
  in sum' : (solveMax heap' sum' m' as)

solveMin :: SkewHeap Int -> Int -> Int -> [Int] -> [Int]
solveMin _    _   _ []     = []
solveMin heap sum m (a:as) =
  let a' = negate a
      heap' = if a' > m
                then push a' $ deleteMin heap
                else heap
      sum' = if a' > m then sum + a - (negate m)
                       else sum
      m' = if a' > m then fromJust $ pop heap'
                     else m
  in sum' : (solveMin heap' sum' m' as)

data SkewHeap a = Empty | Node a (SkewHeap a) (SkewHeap a) deriving (Show, Read, Eq)

merge :: Ord a => SkewHeap a -> SkewHeap a -> SkewHeap a
merge Empty h = h
merge h Empty = h
merge h1@(Node x1 l1 r1) h2@(Node x2 l2 r2)
  | x1 <= x2  = Node x1 (merge h2 r1) l1
  | otherwise = Node x2 (merge h1 r2) l2

singleton :: Ord a => a -> SkewHeap a
singleton x = Node x Empty Empty

push :: Ord a => a -> SkewHeap a -> SkewHeap a
push x heap = merge (singleton x) heap

pop :: Ord a => SkewHeap a -> Maybe a
pop Empty = Nothing
pop (Node x l r) = Just x

deleteMin :: Ord a => SkewHeap a -> SkewHeap a
deleteMin Empty = Empty
deleteMin (Node _ l r) = merge l r
