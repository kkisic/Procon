import Data.List

main = do
  (n:z:w:ws) <- map (read :: String -> Int) . words <$> getLine
  a <- map (read :: String -> Int) . words <$> getLine
  if length a < 2 then print $ abs $ (head a) - w
                  else print $ maximum . map abs $ [(last a) - w, last a - (last . init $ a)]
