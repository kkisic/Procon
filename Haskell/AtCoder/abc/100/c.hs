main = do
  n <- readLn :: IO Int
  ans <- sum . map (f 0 . read) . words <$> getLine
  print ans

f :: Int -> Int -> Int
f n a
  | 1 == mod a 2 = n
  | otherwise    = f (n + 1) $ div a 2
