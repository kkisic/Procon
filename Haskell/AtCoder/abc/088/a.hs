main = do
  n <- readLn :: IO Int
  a <- readLn :: IO Int
  let remain = mod n 500
  if remain <= a
    then putStrLn "Yes"
    else putStrLn "No"
