main = do
  getLine
  input <- concat . map (\x -> [x, x]) . lines <$> getContents
  putStr $ unlines input

