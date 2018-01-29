import Data.Char
import Control.Monad

main = do
  [a,b] <- words <$> getLine
  let a' = octalToDicimal 0 . map intToDigit . decode . map digitToInt . reverse . show . subtract 1 . read $ a
      b' = octalToDicimal 0 . map intToDigit . decode . map digitToInt . reverse $ b
  print $ ((read b) - (read a) + 1) - (b' - a')
  return ()

octalToDicimal :: Int -> String -> Int
octalToDicimal _ []     = 0
octalToDicimal i (x:xs) = (digitToInt x)*(8^i) + octalToDicimal (i+1) xs

decode :: [Int] -> [Int]
decode [] = []
decode (x:xs)
  | elem 4 xs || elem 9 xs = 7:(decode xs)
  | otherwise = (toOctal x):(decode xs)

toOctal :: Int -> Int
toOctal x
  | x >= 9 = 7
  | x >= 4 = x-1
  | otherwise = x
