import Data.List
main = do
  getLine
  putStrLn =<< concat . sort . lines <$> getContents
