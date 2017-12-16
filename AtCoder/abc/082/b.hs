import Data.List

main = do
  s <- sort <$> getLine
  t <- reverse . sort <$> getLine
  if s < t then putStrLn "Yes"
           else putStrLn "No"
