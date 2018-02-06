main = do
  n <- readLn :: IO Int
  w <- (\x -> init x ++ [(init . last $ x)]) . words <$> getLine
  print $ length . filter judge $ w

judge :: String -> Bool
judge "TAKAHASHIKUN" = True
judge "Takahashikun" = True
judge "takahashikun" = True
judge _ = False
