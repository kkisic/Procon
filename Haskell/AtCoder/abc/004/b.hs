import Data.List

main = interact $ reverse . (\x -> (last x) : (init x))
