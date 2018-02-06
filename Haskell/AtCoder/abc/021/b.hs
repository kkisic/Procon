import Data.List

main = do
  n <- readLn :: IO Int
  [a,b] <- map read . words <$> getLine :: IO [Int]
  k <- readLn :: IO Int
  p <- map read . words <$> getLine :: IO [Int]
  let p' = nub p
  if p' == p && notElem a p && notElem b p
    then putStrLn "YES"
    else putStrLn "NO"
