main = do
  input <- getLine
  if input == "5 5 7" || input == "5 7 5" || input == "7 5 5"
    then putStrLn "YES"
    else putStrLn "NO"
