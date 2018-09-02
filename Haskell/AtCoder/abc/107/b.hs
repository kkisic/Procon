import Data.List
main = do
  getLine
  s <- lines <$> getContents
  putStrLn $ unlines . transpose . solve . transpose . solve $ s

solve :: [String] -> [String]
solve ss = let len = length $ head ss
               dots = replicate len '.'
             in filter (/= dots) ss
