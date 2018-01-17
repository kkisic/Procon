main = putStrLn <$> show . sum . map (\x ->  (head x) * (last x) `div` 10) . map (map (read :: String -> Int) . words) . lines =<< getContents
