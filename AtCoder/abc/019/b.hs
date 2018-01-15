import Data.List
main = interact $ (++"\n") . concat . map (\x -> head x:(show . length $ x)) . group . init
