import Data.List

main = do
  getLine
  [t,b] <- lines <$> getContents
  let domino = map length . group $ t
  print $ paint domino 0

paint :: [Int] -> Int -> Int
paint [] _ = 1
paint (x:xs) pre
  | x == 1 && pre == 0 = (flip mod 1000000007) . (*3) $ paint xs 1
  | x == 2 && pre == 0 = (flip mod 1000000007) . (*6) $ paint xs 2
  | x == 1 && pre == 1 = (flip mod 1000000007) . (*2) $ paint xs 1
  | x == 2 && pre == 1 = (flip mod 1000000007) . (*2) $ paint xs 2
  | x == 1 && pre == 2 = (flip mod 1000000007) $ paint xs 1
  | otherwise          = (flip mod 1000000007) . (*3) $ paint xs 2
