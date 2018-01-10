import Data.List

main = do
  s <- getLine
  putStrLn $ unwords . map (show . subtract 1 . length) . group . sort $ s ++ "ABCDEF"
