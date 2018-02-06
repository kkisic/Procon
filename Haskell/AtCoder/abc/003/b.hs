import Data.List

main = do
  x <- getLine
  y <- getLine
  if and . map (judge . replace) $ zip x y
    then putStrLn "You can win"
    else putStrLn "You will lose"

judge :: (Char, Char) -> Bool
judge (x, y) = x == y

replace :: (Char, Char) -> (Char, Char)
replace ('@', y) = ('@', replace' y)
replace (x, '@') = (replace' x, '@')
replace other = other

replace' :: Char -> Char
replace' c = case c of
  'a' -> '@'
  't' -> '@'
  'c' -> '@'
  'o' -> '@'
  'd' -> '@'
  'e' -> '@'
  'r' -> '@'
  _   -> c
