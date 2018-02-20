import Data.Char
main = do
  ans <- read . filter (isDigit) <$> getLine :: IO Int
  print ans
