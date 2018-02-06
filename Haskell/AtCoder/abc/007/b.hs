main = do
  a <- getLine
  putStrLn $ f a

f :: String -> String
f "a" = "-1"
f (s:[]) = "a"
f as@(s:ss) = init as
