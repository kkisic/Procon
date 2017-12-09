main = interact $ (++"\n") . show . (\x -> min x $ (10 - x)) . abs . (\x -> (head x) - (last x)) . map (read :: String -> Int) . lines
