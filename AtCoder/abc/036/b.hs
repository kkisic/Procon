import Data.List

main = do
  getLine
  a <- unlines . map reverse . transpose . lines <$> getContents
  putStr a
