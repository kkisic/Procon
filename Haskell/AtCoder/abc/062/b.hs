main = do
  [h, w] <- map read . words <$> getLine :: IO [Int]
  input <- lines <$> getContents
  let frame = replicate (w+2) '#'
      ans = [frame] ++ (map f input) ++ [frame]
  putStr $ unlines ans

f s = "#" ++ s ++ "#"
