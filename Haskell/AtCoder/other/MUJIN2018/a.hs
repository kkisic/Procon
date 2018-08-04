main = do
  s <- getLine
  if (take 5 s) == "MUJIN"
    then putStrLn "Yes"
    else putStrLn "No"
