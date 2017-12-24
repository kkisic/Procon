import qualified Data.ByteString.Char8 as BC

main = do
  input <- map BC.unpack . BC.split ',' <$> BC.getLine
  putStrLn $ unwords input
