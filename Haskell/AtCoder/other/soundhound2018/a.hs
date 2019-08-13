main = do
  [x,y] <- words <$> getLine :: IO [String]
  let s = [head x, head y]
  if s == "SH"
    then putStrLn "YES"
    else putStrLn "NO"
