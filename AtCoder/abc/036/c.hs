import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  let kind = map head . group . sort $ a
      pair = zip kind [0..]
      table = foldl add M.empty pair
      ans = map (swap table) a
  putStr $ unlines . map show $ ans

add :: M.IntMap Int -> (Int, Int) -> M.IntMap Int
add m (k, v) = M.insert k v m

swap :: M.IntMap Int -> Int -> Int
swap m i = fromJust $ M.lookup i m

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.lines <$> BC.getContents
