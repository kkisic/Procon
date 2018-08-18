import Data.List
main = do
  n <- readLn
  let x = [a * 4 + b * 7 | a <- [0..20], b <- [0..14]]
  if elem n x
    then putStrLn "Yes"
    else putStrLn "No"
