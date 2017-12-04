import Data.List
main = interact $ (++"\n") . snd . last . sortBy (\x y -> compare (fst x) (fst y)) . map (\x -> (length x, head x)) . group . sort . tail . lines
