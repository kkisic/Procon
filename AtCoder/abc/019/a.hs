import Data.List
main = interact $ (++"\n") . show . (!!1) . sort . map (read :: String -> Int) . words
