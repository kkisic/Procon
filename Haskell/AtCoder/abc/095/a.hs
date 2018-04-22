import Data.List

main = do
  s <- length . filter (== 'o') <$> getLine
  print $ 700 + 100 * s
