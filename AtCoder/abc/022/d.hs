import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List
import Control.Monad

main = do
  n <- readLn :: IO Int
  a <- map (\[x,y] -> (realToFrac x, realToFrac y)) <$> replicateM n getIntListBC
  b <- map (\[x,y] -> (realToFrac x, realToFrac y)) <$> replicateM n getIntListBC
  let ag = center (realToFrac n) a
      bg = center (realToFrac n) b
      maxA = maximum $ map (dist ag) a
      maxB = maximum $ map (dist bg) b
  print $ maxB / maxA

center :: Double -> [(Double, Double)] -> (Double, Double)
center n points = let p = unzip points
                      x = sum . map (flip (/) n) $ fst p
                      y = sum . map (flip (/) n) $ snd p
                  in (x, y)

dist :: (Double, Double) -> (Double, Double) -> Double
dist (x1, y1) (x2, y2) = sqrt $ (x1 - x2)^2 + (y1 - y2)^2

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
