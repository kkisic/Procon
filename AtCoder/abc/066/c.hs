import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  a <- getIntListBC
  let odd = fst . unzip . filter (\(x, y) -> mod y 2 /= 0) $ zip a [1..n]
      even = fst . unzip . filter (\(x, y) -> mod y 2 == 0) $ zip a [1..n]
  if n == 1 then print $ head a
            else if 0 == mod n 2
                   then putStrLn $ (unwords . map show . reverse $ even) ++ " " ++ (unwords . map show $ odd)
                   else putStrLn $ (unwords . map show . reverse $ odd) ++ " " ++ (unwords . map show $ even)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
