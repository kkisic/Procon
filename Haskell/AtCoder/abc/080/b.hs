import Data.Char

main = interact $ (\x -> if (mod ((read :: String -> Int) x) (sum . map digitToInt . init $ x)) == 0 then "Yes\n" else "No\n")
