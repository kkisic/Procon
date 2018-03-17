import Data.List
import Control.Monad

main = do
  n <- readLn :: IO Int
  s <- map length . group . sort . fil . map head <$> replicateM n getLine
  let s' = take 5 $ s ++ [0, 0, 0, 0, 0]
      p = nub $ permutations [0, 0, 1, 1, 1]
  print $ sum $ map (solve s') p

solve :: [Int] -> [Int] -> Int
solve []     []     = 1
solve (x:xs) (y:ys) =
  if y == 1
    then x * (solve xs ys)
    else solve xs ys

fil :: String -> String
fil [] = []
fil (s:ss) = if elem s "MARCH"
               then s : fil ss
               else fil ss
