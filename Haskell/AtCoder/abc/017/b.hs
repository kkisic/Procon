main = do
  s <- getLine
  if solve s
    then putStrLn "YES"
    else putStrLn "NO"

solve :: String -> Bool
solve [] = True
solve ('c':'h':s) = solve s
solve ('o':s) = solve s
solve ('k':s) = solve s
solve ('u':s) = solve s
solve (_:s) = False
