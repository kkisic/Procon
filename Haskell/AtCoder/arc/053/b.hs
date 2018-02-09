import Data.List

main = do
  s <- getLine
  let ss = map length . group . sort $ s
      x = length $ filter odd ss
  if x <= 1
    then print $ length s
    else print . (+1) . (*2) $ (flip div 2 $ length s - x) `div` x
