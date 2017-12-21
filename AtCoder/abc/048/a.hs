main = do
  [_, x, _] <- words <$> getLine
  putStrLn $ "A" ++ [head x] ++ "C"
