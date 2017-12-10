main = interact $ (++"\n") . show . solve . map (read :: String -> Int) . words . last . lines

solve :: [Int] -> Int
solve s = if and . map even $ s
              then 1 + solve (map (flip div 2) s)
              else 0
