import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  b <- getIntListBC
  let (x, y) = solve (zip a b) (0, 0)
      sa = sum a
      sb = sum b
      diff = sb - sa
  if (diff-x)*2 == (diff-y) && diff >= x && diff >= y
    then putStrLn "Yes"
    else putStrLn "No"

solve :: [(Int, Int)] -> (Int, Int) -> (Int, Int)
solve [] (x, y) = (x, y)
solve ((a,b):s) (x, y)
  | a < b =
  let c = if odd (b-a)
            then (+1) $ div (b-a) 2
            else div (b-a) 2
  in solve ((a+c*2, b):s) (x+c, y)
  | a > b =
  let c = a-b
  in solve ((a, b+c):s) (x, y+c)
  | otherwise = solve s (x, y)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
