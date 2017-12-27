import Data.List
main = interact $ (++"\n") . show . length . group . sort . words
