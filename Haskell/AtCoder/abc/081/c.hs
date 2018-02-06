import Data.List

main = do
  k <- (read :: String -> Int) . last . words <$> getLine
  nums <- sortBy (\x y -> compare (length x) (length y)) . group . sort . map (read :: String -> Int) . words <$> getLine
  let kind = length nums
  if kind > k then putStrLn $ show . length . concat . take (kind - k) $ nums
              else putStrLn "0"

