main = putStrLn <$> (\x -> if (length . head $ x) > (length . last $ x) then head x else last x) . lines =<< getContents
