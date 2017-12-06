main = interact $ (++"\n") . show . (\x -> (maximum x) - (minimum x)) . map (read :: String -> Int) . words . last . lines
