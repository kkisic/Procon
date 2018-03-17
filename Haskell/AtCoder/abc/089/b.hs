import Data.List

main = do
  getLine
  s <- group . sort . words <$> getLine
  if length s == 3
    then putStrLn "Three"
    else putStrLn "Four"
