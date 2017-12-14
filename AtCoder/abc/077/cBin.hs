import Data.List
import Data.ByteString.Char8 as BC (words, getLine, readInt)
import Data.Maybe (fromJust)

main = do
  {-
  n <- (read :: String -> Int) <$> getLine
  a <- sort . map (read :: String -> Int) . words <$> getLine
  b <- sort . map (read :: String -> Int) . words <$> getLine
  c <- sort . map (read :: String -> Int) . words <$> getLine
  print . sum $ zipWith (*) (scanl1 (+) $ ltList a b) (gtList (length c) c b)
  let a = [0..10^5]
      b = replicate (10^5) 1
      c = replicate (10^5) 2
      d = replicate (10^5) 3
  printAns b c d
  -}
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
