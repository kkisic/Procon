import Data.List

main = do
  n <- readLn :: IO Int
  a <- map read . words <$> getLine :: IO [Int]
  if mod (sum a) n /= 0
    then putStrLn "-1"
    else let ave = div (sum a) n
         in print $ solve a ave 0

solve :: [Int] -> Int -> Int -> Int
solve []     _ s = 0
solve (x:xs) n s
  | s /= 0    = (+1) $ solve xs n $ s + x -n
  | otherwise = solve xs n $ s + x - n
