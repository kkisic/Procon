import Data.List
main = do
  input <- getLine
  print $ judge $ init input

judge :: String -> Int
judge s = let l = length s `div` 2
          in if (take l s) == (drop l s)
               then l * 2
               else judge $ init s
