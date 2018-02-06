import Data.List
main = do
  getLine
  a <- map read . lines <$> getContents :: IO [Int]
  print $ length . group . sort $ a

