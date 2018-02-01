import Data.Char
import Data.List

main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  s <- getLine
  putStrLn $ solve 0 (n-k) s $ sort s

solve :: Int -> Int -> String -> String -> String
solve _ _     []     _   = []
solve n fixed origin set =
  let c = decide n fixed origin set set
  in if c == head origin
       then c : (solve (n+1) fixed (tail origin) (set \\ [c]))
       else c : (solve n fixed (tail origin) (set \\ [c]))

decide :: Int -> Int -> String -> String -> String -> Char
decide n fixed origin set []     = '!'
decide n fixed origin set (c:cs) =
  let k = length $ (set \\ [c]) \\ tail origin
      l = if head origin == c then 1 else 0
  in if fixed <= n + (length origin - k - 1) + l
       then c
       else decide n fixed origin set cs
