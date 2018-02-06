import Data.List
main = do
  input <- foldl f True . group . sort <$> getLine
  if input then putStrLn "yes"
           else putStrLn "no"

f :: Bool -> [Char] -> Bool
f b s = b && (1 == length s)
