import Data.List

main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  hate <- concat . words <$> getLine
  print $ solve n hate

solve :: Int -> String -> Int
solve n hate = let sn = show n
               in if (sn \\ hate) == sn
                    then n
                    else solve (n+1) hate
