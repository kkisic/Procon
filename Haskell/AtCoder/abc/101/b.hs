import Data.Char

main = do
  s <- getLine
  let x = read s
      y = f s 0
  if mod x y == 0
    then putStrLn "Yes"
    else putStrLn "No"

f :: String -> Int -> Int
f [] n = n
f (x:xs) n = f xs $ n + (ord x) - (ord '0')
