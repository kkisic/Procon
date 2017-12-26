import qualified Data.ByteString.Char8 as BC

main = do
  s <- reverse . BC.unpack <$> BC.getLine
  if solve s then putStrLn "YES"
             else putStrLn "NO"

solve :: String -> Bool
solve s
  | length s >= 7 && (take 7 s) == "remaerd" = solve $ drop 7 s
  | length s >= 6 && (take 6 s) == "resare" = solve $ drop 6 s
  | length s >= 5 && (take 5 s) == "maerd" = solve $ drop 5 s
  | length s >= 5 && (take 5 s) == "esare" = solve $ drop 5 s
  | otherwise = length s == 0
