import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- readLn :: IO Int
  input <- getIntListBC
  let student = map snd . reverse . sort $ zip input [1..n]
  putStr $ unlines . map show $ student

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
