import Data.Char
{-
main = do
  input <- getLine
  let x = (read :: String -> Int) input
      y = sum . map (read :: Char -> Int) $ x
      -}



main = interact $ (\x -> if (mod ((read :: String -> Int) x) (sum . map digitToInt . init $ x)) == 0 then "Yes\n" else "No\n")
