main = do
  a <- getLine
  b <- getLine
  c <- getLine
  putStrLn $ game 'a' a b c

game :: Char -> String -> String -> String -> String
game 'a' [] _ _ = "A"
game 'b' _ [] _ = "B"
game 'c' _ _ [] = "C"
game 'a' (a:as) b c = game a as b c
game 'b' a (b:bs) c = game b a bs c
game 'c' a b (c:cs) = game c a b cs
