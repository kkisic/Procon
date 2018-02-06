import Data.List

main = do
  s <- getLine
  k <- readLn :: IO Int
  print $ length . group . sort $ split s k

split :: String -> Int -> [String]
split []       k = []
split s@(t:ts) k
  | length s < k = []
  | otherwise    = (take k s) : (split ts k)
