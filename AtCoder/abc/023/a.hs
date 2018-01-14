import Data.Char

main = interact $ (++"\n") . show . sum . map digitToInt . init
