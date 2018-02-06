import Data.Char
main = interact $ (++"\n") . map (toUpper . head) . words
