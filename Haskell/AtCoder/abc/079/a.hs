import Data.Char
import Data.List
main = interact $ (\x -> if x >= 3 then "Yes\n" else "No\n") . maximum . map length . group . map digitToInt . init
