import qualified Data.ByteString.Char8 as BC

main = do
  x <- map read . words <$> getLine :: IO [Int]
  s <- map (length . BC.unpack) . BC.split '-' <$> BC.getLine
  if x == s then putStrLn "Yes"
            else putStrLn "No"
