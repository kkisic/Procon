import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Text.Printf

main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  input <- sortBy compareSalt <$> getInt2DListBC
  let ans = bisection 0 k 0 100 input
  putStrLn $ printf "%.9f" ans

compareSalt :: [Double] -> [Double] -> Ordering
compareSalt [w1, p1] [w2, p2] = compare p2 p1

bisection :: Int -> Int -> Double -> Double -> [[Double]] -> Double
bisection 100 _ l r salt = l
bisection n k l r salt
  | l == r = l
  | otherwise = let m = (l + r) / 2
                    b = solve k m salt
                in if b
                     then bisection (n+1) k m r salt
                     else bisection (n+1) k l m salt

solve :: Int -> Double -> [[Double]] -> Bool
solve k x salt = let salt' = take k . sortBy compareSalt $ map (f x) salt
               in sumSalt salt' >= 0

sumSalt :: [[Double]] -> Double
sumSalt salt = sum $ map last salt

f :: Double -> [Double] -> [Double]
f x [w, p] = let s = w * (p - x) / 100
             in [w, s]

bsToInt :: BC.ByteString -> Double
bsToInt = realToFrac . fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Double]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

