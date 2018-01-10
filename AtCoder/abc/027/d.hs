import Data.List

main = do
  s <- getLine
  let m = flip div 2 . length $ filter (=='M') s
      pl = length $ filter (=='+') s
      mi = length $ filter (=='-') s
      c = sort $ count s pl mi
  print $ (sum $ drop m c) - (sum $ take m c)

count :: String -> Int -> Int -> [Int]
count []      _  _  = []
count ('M':s) pl mi = (pl-mi) : count s pl mi
count ('+':s) pl mi = count s (pl-1) mi
count ('-':s) pl mi = count s pl (mi-1)
