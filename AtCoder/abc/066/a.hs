import Data.List
main = interact $ (++"\n") . show . sum . init . sort . map (read :: String -> Int) . words
