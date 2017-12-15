import Data.List
import Data.ByteString.Char8 as BC (words, getLine, readInt)
import Data.Maybe (fromJust)

main = do
  n <- fst . fromJust . BC.readInt <$> BC.getLine
  a <- sort . map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
  b <- sort . map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
  c <- sort . map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
  printAns a b c

p :: Int -> Int -> Int
p x y = x + y

m :: Int -> Int -> Int
m x y = x * y

ltList' :: [Int] -> [Int] -> [Int]
ltList' a b = scanl1 p $ ltList a b

ltList :: [Int] -> [Int] -> [Int]
ltList _  []     = []
ltList [] (b:bs) = 0 : ltList [] bs
ltList a  (b:bs) = let lt = length $ takeWhile (< b) a
                       remain = drop lt a
                   in lt : ltList remain bs

gtList :: Int -> [Int] -> [Int] -> [Int]
gtList n _  []     = []
gtList n [] (b:bs) = 0 : gtList n [] bs
gtList n a  (b:bs) = let le =  length $ takeWhile (<= b) a
                         remain = drop le a
                     in (n-le) : gtList (n-le) remain bs

printAns :: [Int] -> [Int] -> [Int] -> IO ()
printAns a b c = print . sum $ zipWith m (ltList' a b) (gtList (length c) c b)
