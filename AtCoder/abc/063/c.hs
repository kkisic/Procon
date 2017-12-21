import Data.List
main = do
  getLine
  input <- map read . lines <$> getContents :: IO [Int]
  let score = sum input
      notMod10 = filter ((/=0) . flip mod 10) $ sort input
  if mod score 10 == 0 then if length notMod10 == 0
                              then print 0
                              else print $ score - (head notMod10)
                       else print score
