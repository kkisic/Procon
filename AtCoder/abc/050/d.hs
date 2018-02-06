import qualified Data.Map.Strict as M
import Data.Maybe (fromJust)
import Data.Array.IO

type Memo = M.Map (Int, Int) Int

modN = 10^9+7

main = do
  n <- readLn :: IO Int
  let (ans, memo) = solve M.empty n n
  print ans

solve :: Memo -> Int -> Int -> (Int, Memo)
solve memo 0 0 = (1, M.insert (0, 0) 1 memo)
solve memo s x
  | s < 0 || x < 0 = (0, memo)
  | otherwise =
  let ans = M.lookup (s, x) memo
  in if ans == Nothing
       then let (a1, m1) = solve memo (div s 2) (div x 2)
                (a2, m2) = solve m1 (div (s-1) 2) (div (x-1) 2)
                (a3, m3) = solve m2 (div (s-2) 2) (div x 2)
                a = mod (a1+a2+a3) modN
            in (a, M.insert (s, x) a m3)
       else (fromJust ans, memo)
