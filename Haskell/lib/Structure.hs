import Data.Bits
import Data.Array.IO

--Binyary Indexed Tree
type BIT = IOUArray Int Int

query :: BIT -> Int -> IO Int
query bit 0 = return 0
query bit i = do
  x <- readArray bit i
  y <- query bit $ i-(i.&.(negate i))
  return $ x + y

update :: BIT -> (Int, Int) -> IO BIT
update bit (i, x) = do
  m <- snd <$> getBounds bit
  if i > m
    then return bit
    else do
      y <- readArray bit i
      writeArray bit i $ x + y
      update bit ((i+(i.&.(negate i))), x)



--Skew Heap : for Priority-Queue
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
