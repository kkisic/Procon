main = interact $ (++"\n") . show . sum . map (flower . (read :: String -> Int)) . words . last . lines

flower :: Int -> Int
flower x
  | mod x 6 >= 3 = (mod x 6) - 3
  | mod x 6 == 0 = 3
  | otherwise    = (mod x 6) - 1
