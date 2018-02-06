import Data.List
main = do
  input <- map (read :: String -> Int) . words <$> getLine
  let w = head input
      min = (+ w) . minimum . tail $ input
      max = maximum . tail $ input
  if min < max then print $ max - min
               else print 0
