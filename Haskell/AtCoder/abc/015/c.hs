import Data.Bits

main = do
  [n,k] <- map read . words <$> getLine :: IO [Int]
  t <- map (map read . words) . lines <$> getContents :: IO [[Int]]
  if solve t [] 0
    then putStrLn "Found"
    else putStrLn "Nothing"

solve :: [[Int]] -> [Int] -> Int -> Bool
solve (x:[]) y i = or $ map (solve' (i:y)) x
solve (x:xs) y i = or $ map (solve xs (i:y)) x

solve' :: [Int] -> Int -> Bool
solve' x y = 0 == foldl xor y x
