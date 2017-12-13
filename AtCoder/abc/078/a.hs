main = do
  input <- words <$> getLine
  putStrLn $ comp (head input) (last input)

comp :: String -> String -> String
comp s t = case compare s t of
            LT -> "<"
            GT -> ">"
            EQ -> "="
