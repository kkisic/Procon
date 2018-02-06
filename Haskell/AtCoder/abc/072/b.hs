main = do
  input <- getLine
  putStrLn $ f input

f :: String -> String
f [] = []
f (s:[]) = [s]
f (s:t:ts) = s : f ts
