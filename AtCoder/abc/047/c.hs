import qualified Data.ByteString.Char8 as BC

main = do
  stone <- BC.getLine
  let white = length . filter (/="") . map BC.unpack . BC.split 'B' $ stone
      black = length . filter (/="") . map BC.unpack . BC.split 'W' $ stone
  print $ white + black - 1

