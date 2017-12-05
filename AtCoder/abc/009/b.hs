import Data.List
main = interact $ (++"\n") . show . head . last . init . group . sort . map (read :: String -> Int) . tail . lines
