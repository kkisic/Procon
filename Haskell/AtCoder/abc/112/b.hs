import Data.List
main = do
  [n,t] <- map read . words <$> getLine
  a <- transpose . map (map read . words) . lines <$> getContents
  let b = filt t (a !! 0) (a !! 1)
  if length b > 0
    then print $ minimum b
    else putStrLn "TLE"

filt :: Int -> [Int] -> [Int] -> [Int]
filt _ [] [] = []
filt t (x:xs) (y:ys) = if y <= t
                         then x : (filt t xs ys)
                         else filt t xs ys
