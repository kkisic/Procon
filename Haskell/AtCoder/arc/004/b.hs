import Data.List

main = do
  n <- readLn :: IO Int
  d <- sort . map read . lines <$> getContents
  let m = last d
      remain = sum $ init d
  print $ sum d
  if m > remain
    then print $ m - remain
    else print 0
