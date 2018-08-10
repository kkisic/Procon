main = do
  n <- readLn
  s <- getLine
  t <- getLine
  let result = map (\x -> solve (drop x s) t) [0..n]
  out result [n..2*n]

solve :: String -> String -> Bool
solve [] _ = True
solve (s:ss) (t:ts) = if s == t
                        then solve ss ts
                        else False

out :: [Bool] -> [Int] -> IO ()
out (True:bs) (i:is) = print i
out (False:bs) (i:is) = out bs is
