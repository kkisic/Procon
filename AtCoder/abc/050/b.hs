import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  t <- getIntListBC
  m <- readLn :: IO Int
  px <- getInt2DListBC
  let ans = map (drink t) px
  putStr . unlines . map show $ ans

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents

drink :: [Int] -> [Int] -> Int
drink t [p, x] = sum $ take (p-1) t ++ [x] ++ drop p t
