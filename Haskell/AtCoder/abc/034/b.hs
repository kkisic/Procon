main = do
  n <- readLn :: IO Int
  if mod n 2 == 0 then print $ n-1
                  else print $ n+1
