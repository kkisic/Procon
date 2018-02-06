import Data.List

main = do
  n <- (read :: String -> Int) <$> getLine
  input <- map (read :: String -> Int) . words <$> getLine
  let max = maximum input
      min = minimum input
  solve min max input

increase :: Int -> [[Int]]
increase n = [[a, a+1] | a <- [1..n-1]]

decrease :: Int -> [[Int]]
decrease n = reverse [[a+1, a] | a <- [1..n-1]]

makeList :: Int -> Int -> [[Int]]
makeList n m = [[m, a] | a <- [1..n], a /= m]

solve :: Int -> Int -> [Int] -> IO ()
solve min max s
  | min >= 0          = do
    print (length s - 1)
    putStr . toString . increase $ length s
  | max <= 0          = do
    print (length s - 1)
    putStr . toString . decrease $ length s
  | abs min < abs max = do
    let maxIndex = (+1) . head . elemIndices max $ s
    print $ (length s - 1) * 2
    putStr $ toString $ makeList (length s) maxIndex
    putStr . toString . increase $ length s
  | otherwise         = do
    let minIndex = (+1) . head . elemIndices min $ s
    print $ (length s - 1) * 2
    putStr $ toString $ makeList (length s) minIndex
    putStr . toString . decrease $ length s

toString :: [[Int]] -> String
toString = unlines . map (unwords . map show)
