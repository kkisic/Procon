import Data.List

main = do
  s <- map read . words <$> getLine :: IO [Int]
  let p = sortBy (\x y -> compare y x) . nub . map sum . map (take 3) $ permutations s
  print $ p !! 2
