import Data.List
main = interact $ unlines . map (show . fst) . sortBy (\x y -> compare (fst . snd $ x) (fst .snd $ y)) . zip [3,2,1] . sortBy (\x y -> compare (snd x) (snd y)) . zip [1,2,3] . map (read :: String -> Int) . lines
