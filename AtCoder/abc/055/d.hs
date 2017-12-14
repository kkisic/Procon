import Data.List
import qualified Data.ByteString.Char8 as BC (words, getLine, unpack)

data Animal = S | W deriving (Show, Eq)

main = do
  n <- (read :: String -> Int) <$> getLine
  input <- BC.unpack <$> BC.getLine
  let pattern = [[a,b] | a <- [S, W], b <- [S, W]]
      result = map (solve input) pattern
      resultTF = map judge result
      ansIdx = elemIndices True resultTF
  if length ansIdx > 0 then putStrLn . toString $ result !! (head ansIdx)
                       else print $ -1

rev :: Animal -> Animal
rev S = W
rev W = S

solve :: String -> [Animal] -> [Animal]
solve (s:tt) (a:b:bs)
  | s == 'o' && b == S = solve' tt (a:b:bs) ++ [a]
  | s == 'o' && b == W = solve' tt (a:b:bs) ++ [rev a]
  | s == 'x' && b == S = solve' tt (a:b:bs) ++ [rev a]
  | otherwise          = solve' tt (a:b:bs) ++ [a]

solve' :: String -> [Animal] -> [Animal]
solve' []     s        = s
solve' (s:tt) (a:b:bs)
  | s == 'o' && a == S = solve' tt (b:a:b:bs)
  | s == 'o' && a == W = solve' tt ((rev b):a:b:bs)
  | s == 'x' && a == S = solve' tt ((rev b):a:b:bs)
  | otherwise          = solve' tt (b:a:b:bs)

judge :: [Animal] -> Bool
judge []       = False
judge (_:[])   = False
judge (a:b:bs) = a == (last . init $ bs) && b == last bs

toString :: [Animal] -> String
toString = concat . map show . reverse . init . tail
