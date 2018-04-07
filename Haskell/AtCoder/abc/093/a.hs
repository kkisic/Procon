import Data.List

main = do
  s <- sort <$> getLine
  if s == "abc"
    then putStrLn "Yes"
    else putStrLn "No"
