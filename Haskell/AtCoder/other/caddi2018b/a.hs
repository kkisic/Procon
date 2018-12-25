import Data.List
main = do
  n <- getLine
  print $ length . filter (== '2') $ n
