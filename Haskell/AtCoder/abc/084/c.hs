import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  input <- getInt2DListBC
  let ans = map (solve input) [1..n-1]
  putStr . unlines . map show $ ans ++ [0]

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

toNext :: Int -> [Int] -> Int
toNext now [c, s, f]
  | now < s = s + c
  | otherwise = let n = if (now - s) `mod` f == 0
                          then (now - s) `div` f
                          else (+1) $ (now - s) `div` f
                in (s + n * f + c)

solve :: [[Int]] -> Int -> Int
solve t i = let [c,s,f] = t !! (i - 1)
            in foldl toNext s $ drop (i-1) t
