main = do
  s <- lines <$> getContents
  print $ length . filter (==True) $ map (elem 'r') s
