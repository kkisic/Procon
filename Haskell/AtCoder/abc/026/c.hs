import qualified Data.IntMap as M
import Data.Array.IO
import Data.Maybe (fromJust)
import Control.Monad

type Person = M.IntMap [Int]
type Memo = IOUArray Int Int

main = do
  n <- readLn :: IO Int
  b <- map read . lines <$> getContents :: IO [Int]
  memo <- newArray (1, n) 0 :: IO Memo
  let p = zip b [2..n]
      member = foldl register M.empty p
  foldM (update member) memo $ reverse [1..n]
  ans <- readArray memo 1
  print ans

register :: Person -> (Int, Int) -> Person
register p (x, y) = let b = M.lookup x p
                    in if b == Nothing
                         then M.insert x [y] p
                         else let b' = fromJust b
                              in M.insert x (y:b') p

update :: Person -> Memo -> Int -> IO Memo
update p memo x
  | M.lookup x p == Nothing = do
    writeArray memo x 1
    return memo
  | otherwise = do
    let b = fromJust $ M.lookup x p
    s <- mapM (readArray memo) b
    writeArray memo x $ (minimum s) + (maximum s) + 1
    return memo
