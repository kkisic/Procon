import Data.List

main = do
  s <- sort <$> getLine
  n <- readLn :: IO Int
  let ss = [[i,j] | i <- s, j <- s]
  putStrLn $ ss !! (n-1)
