import Data.List

main = do
  a <- group . sort . map read . words <$> getLine :: IO [[Int]]
  if length a /= 1
    then let b = head a
         in if length b == 1
              then print $ head b
              else print $ head $ last a
    else print $ head $ head a
