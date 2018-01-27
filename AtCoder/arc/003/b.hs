import Data.List

main = do
  n <- readLn :: IO Int
  s <- map reverse . sort . map reverse . lines <$> getContents
  putStr $ unlines s
