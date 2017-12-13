import Control.Monad
import Data.List

main = do
  nm <- map (read :: String -> Int) . words <$> getLine
  student <- map (map (read :: String -> Int) . words) <$> replicateM (head nm) getLine
  check <- map (map (read :: String -> Int) . words) <$> replicateM (last nm) getLine
  putStrLn . unlines $ map (show . (\x -> (+1) . minIndex $ map (dist x) check)) student

dist :: [Int] -> [Int] -> Int
dist (x1:y1:_) (x2:y2:_) = abs (x1 - x2) + abs (y1 - y2)

minIndex :: [Int] -> Int
minIndex xs = head . elemIndices (minimum xs) $ xs
