import qualified Data.ByteString.Char8 as BC

main = do
  input <-  BC.getLine
  let p = length . BC.elemIndices 'p' $ input
      num = length . BC.unpack $ input
  print $ (div num 2) - p
