import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.List

main = do
  k <- readLn :: IO Int
  a <- map bsToInt . reverse . BC.words <$> BC.getLine
  let ans = solve a (2, 2)
  if ans == Nothing
    then print $ negate 1
    else let (l, r) = fromJust ans
         in putStrLn $ show l ++ " " ++ show r
  print $ solve' a (2, 2)

solve :: [Int] -> (Int, Int) -> Maybe (Int, Int)
solve [] (l, r) = Just (l, r)
solve (a:as) (l, r) =
  let m = div l a
      n = div r a
      o = div (l-1) a
  in if n - o > 0
       then if mod l a == 0
              then solve as (a*m, a*(n+1)-1)
              else solve as (a*(m+1), a*(n+1)-1)
       else Nothing

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt
