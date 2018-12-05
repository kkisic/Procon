import Data.List
main = do
  x <- readLn
  let a = [3, 5, 7]
  if elem x a
    then putStrLn "YES"
    else putStrLn "NO"
