main = do
  input <- last . lines <$> getContents
  let left = fst $ countLeft input (0, 0)
      right = fst $ countRight input (0, 0)
  putStrLn $ (replicate right '(') ++ input ++ (replicate left ')')

countLeft :: String -> (Int, Int) -> (Int, Int)
countLeft [] (l, r) = (l, r)
countLeft ('(':ss) (l, r) = countLeft ss (l+1, r)
countLeft (')':ss) (l, r) = if l > 0 then countLeft ss (l-1, r)
                                     else countLeft ss (l, r)
countLeft (_:ss) (l, r) = countLeft ss (l, r)


countRight :: String -> (Int, Int) -> (Int, Int)
countRight [] (r, l) = (r, l)
countRight ('(':ss) (r, l) = countRight ss (r, l+1)
countRight (')':ss) (r, l) = if l > 0 then countRight ss (r, l-1)
                                      else countRight ss (r+1, l)
countRight (_:ss) (r, l) = countLeft ss (r, l)
