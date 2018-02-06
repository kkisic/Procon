import Data.Int
modNum = 1000000007

main = do
  nm <- map (read :: String -> Int) . words <$> getLine
  inputX <- map (read :: String -> Int) . words <$> getLine
  inputY <- map (read :: String -> Int) . words <$> getLine
  let n = head nm
      m = last nm
      x = flip mod modNum . sum . zipWith (solve (length inputX)) [1..n] $ inputX
      y = flip mod modNum . sum . zipWith (solve (length inputY)) [1..m] $ inputY
  putStrLn . show $ (flip mod modNum $ x * y)

solve :: Int -> Int -> Int -> Int
solve n k = (flip mod modNum) . ((*) (2 * k - n - 1))
