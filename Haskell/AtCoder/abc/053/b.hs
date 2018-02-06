import qualified Data.ByteString.Char8 as BC

main = do
  input <- BC.unpack <$> BC.getLine
  let r = reverse input
      a = solve input 'A' 0
      z = solve r 'Z' 0
  print $ (length input) - a - z

solve :: String -> Char -> Int -> Int
solve (a:as) c i
  | a == c = i
  | otherwise = solve as c $ i + 1
