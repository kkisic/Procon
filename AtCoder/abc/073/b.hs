main = do
  getLine
  input <- map ((\[l,r] -> (read l, read r)) . words) . lines <$> getContents :: IO [(Int, Int)]
  putStrLn . show . sum $ map (\(l, r) -> r - l + 1) input
