main = do
  input <- map (read :: String -> Int) . lines <$> getContents
  if notElem (head input) (tail input) && 100 >= solve 0 (head input) (tail input)
    then putStrLn "YES"
    else putStrLn "NO"

solve :: Int -> Int -> [Int] -> Int
solve c n ng
  | n - 3 >= 0 && notElem (n-3) ng = solve (c+1) (n-3) ng
  | n - 2 >= 0 && notElem (n-2) ng = solve (c+1) (n-2) ng
  | n - 1 >= 0 && notElem (n-1) ng = solve (c+1) (n-1) ng
  | n == 0                         = c
  | otherwise                      = 101
