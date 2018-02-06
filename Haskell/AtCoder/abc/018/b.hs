main = do
  s <- getLine
  n <- readLn :: IO Int
  input <- map (map read . words) . lines <$> getContents :: IO [[Int]]
  let ans = foldl solve s input
  putStrLn ans

solve :: String -> [Int] -> String
solve s [l,r] = (take (l-1) s) ++ (reverse . drop (l-1) . take r $ s) ++ (drop r s)
