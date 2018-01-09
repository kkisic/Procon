import Data.List
main = do
  n <- group <$> getLine
  if length n == 1 then putStrLn "SAME"
                   else putStrLn "DIFFERENT"
