import Data.Char

main = do
  input <- (read :: String -> Int) <$> getLine
  putStrLn $ map intToDigit $ solve 0 (mod input 30) [1,2,3,4,5,6]

solve :: Int -> Int -> [Int] -> [Int]
solve i n ls = if i == n
                    then ls
                    else case i `mod` 5 of
                      0 -> solve (i+1) n $ [ls !! 1] ++ [ls !! 0] ++ (drop 2 ls)
                      1 -> solve (i+1) n $ (take 1 ls) ++ [ls !! 2] ++ [ls !! 1] ++ (drop 3 ls)
                      2 -> solve (i+1) n $ (take 2 ls) ++ [ls !! 3] ++ [ls !! 2] ++ (drop 4 ls)
                      3 -> solve (i+1) n $ (take 3 ls) ++ [ls !! 4] ++ [ls !! 3] ++ (drop 5 ls)
                      4 -> solve (i+1) n $ (take 4 ls) ++ [ls !! 5] ++ [ls !! 4]
