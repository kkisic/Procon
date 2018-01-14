main = do
  n <- readLn :: IO Int
  s <- getLine
  let (k, ans) = solve n 1 "b"
  if s == ans
    then print k
    else print $ negate 1

solve :: Int -> Int -> String -> (Int, String)
solve n k s
  | length s >= n = (k-1, s)
  | mod k 3 == 0  = solve n (k+1) $ "b" ++ s ++ "b"
  | mod k 3 == 1  = solve n (k+1) $ "a" ++ s ++ "c"
  | mod k 3 == 2  = solve n (k+1) $ "c" ++ s ++ "a"
