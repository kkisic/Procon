main = do
  s <- getLine
  print $ f s 0

f :: String -> Int -> Int
f [] n = n
f ('+':s) n = f s $ n + 1
f ('-':s) n = f s $ n - 1
