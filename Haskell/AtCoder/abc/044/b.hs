import Data.List
main = do
  w <- filter (odd) . map length . group . sort <$> getLine
  if w == [] then putStrLn "Yes"
             else putStrLn "No"
