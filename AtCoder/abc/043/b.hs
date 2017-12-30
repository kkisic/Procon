main = do
  input <- getLine
  putStrLn . reverse $ solve input []

solve :: String -> String -> String
solve []       x  = x
solve ('B':as) [] = solve as []
solve ('B':as) (x:xs) = solve as xs
solve (a:as) x = solve as (a:x)
