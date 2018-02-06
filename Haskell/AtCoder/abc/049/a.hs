main = do
  a <- getLine
  if elem a ["a", "i", "u", "e", "o"]
    then putStrLn "vowel"
    else putStrLn "consonant"
