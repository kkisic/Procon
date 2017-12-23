import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Char
import Data.List

main = do
  input <- BC.getLine
  let x = map digitToInt . BC.unpack $ input
  print $ solve x

solve :: [Int] -> Int
solve x
  | length x == 1 = 1
  | mod (length x) 2 == 0 = let n = length x
                                mid = div n 2
                                left = reverse $ take mid x
                                right = drop mid x
                            in (div n 2) + (solve' (head left) left right)
  | otherwise    = let n = length x
                       mid = div n 2
                       left = reverse $ take mid x
                       right = drop (mid+1) x
                   in 1 + (div n 2) + (solve' (x !! mid) left right)

solve' :: Int -> [Int] -> [Int] -> Int
solve' n []     []     = 0
solve' n (l:ls) (r:rs)
  | n == r && l == r = 1 + (solve' n ls rs)
  | otherwise        = 0
