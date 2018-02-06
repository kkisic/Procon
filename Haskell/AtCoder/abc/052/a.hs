main = do
  [a,b,c,d] <- map read . words <$> getLine :: IO [Int]
  let s1 = a * b
      s2 = c * d
  if s1 > s2 then print s1
             else print s2
