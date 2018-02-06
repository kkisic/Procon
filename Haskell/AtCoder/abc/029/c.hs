import Data.List
main = do
  n <- readLn :: IO Int
  let p = [[a, b, c, d, e, f, g, h] | h <- "abc", g <- "abc", f <- "abc", e <- "abc", d <- "abc", c <- "abc", b <- "abc", a <- "abc"]
  putStr $ unlines . sort . map (take n) $ take (3^n) p
