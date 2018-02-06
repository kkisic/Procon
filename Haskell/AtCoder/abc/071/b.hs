import Data.List
main = do
  let abc = "abcdefghijklmnopqrstuvwxyz"
  s <- sort . nub <$> getLine
  if abc == s then putStrLn "None"
              else putStrLn $ (:[]) . head $ abc \\ s
