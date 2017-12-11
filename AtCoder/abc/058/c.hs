import Data.List
main = interact $ (++"\n") . sort . foldl1 (\x y -> x \\ (x \\ y)) . tail . lines
