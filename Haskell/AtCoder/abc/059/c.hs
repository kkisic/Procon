import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

main = do
  n <- readLn :: IO Int
  (a:as) <- getIntListBC
  let ans1 = solve a as
      x = (+1) $ abs a
      ans2 = if a >= 0 then x + solve (-1) as
                       else x + solve 1 as
  print $ min ans1 ans2

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

solve :: Int -> [Int] -> Int
solve _ []    = 0
solve s (a:as)
  | s > 0     = let sum = s + a
                in if sum >= 0
                     then (sum + 1) + solve (-1) as
                     else solve sum as
  | s < 0     = let sum = s + a
                in if sum <= 0
                     then ((negate sum) + 1) + solve 1 as
                     else solve sum as
  | otherwise = 1 + solve 1 (a:as)
