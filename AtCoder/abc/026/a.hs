main = do
  n <- readLn :: IO Int
  if even n
    then print $ (div n 2)^2
    else print $ (div n 2) * ((+1) $ div n 2)
