main = do
  n <- readLn
  s <- getLine
  if solve n s
    then putStrLn "Yes"
    else putStrLn "No"

solve :: Int -> String -> Bool
solve 0 _ = True
solve n [] = False
solve n ('+':ss) = solve (n + 1) ss
solve n ('-':ss) = solve (n - 1) ss
