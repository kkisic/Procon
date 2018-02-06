import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  t <- map (\[x,y,z] -> (x,y,z)) <$> getInt2DListBC
  if solve (0, 0, 0) t
    then putStrLn "Yes"
    else putStrLn "No"

solve :: (Int, Int, Int) -> [(Int, Int, Int)] -> Bool
solve (_, _, _) [] = True
solve (t1, x1, y1) ((t2, x2, y2):s) =
  let t = t2 - t1
      x = abs $ x2 - x1
      y = abs $ y2 - y1
  in if t < x + y || mod (t-(x+y)) 2 /= 0
       then False
       else solve (t2, x2, y2) s

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getInt2DListBC :: IO [[Int]]
getInt2DListBC = map (map bsToInt . BC.words) . BC.lines <$> BC.getContents
