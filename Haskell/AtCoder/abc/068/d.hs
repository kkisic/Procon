import Data.Maybe (fromJust)
import Data.List

main = do
  k <- readLn :: IO Int
  let ans = f k 2
  case k of
    0 -> do putStrLn "2"
            putStrLn "1 1"
    1 -> do putStrLn "2"
            putStrLn "2 0"
    _ -> do let a = fromJust ans
            print $ length a
            putStrLn . unwords . map show $ a

make :: Int -> [Int]
make n = [0..n-1]

solve :: Int -> Int -> [Int] -> Maybe [Int]
solve i 0 p      = if maximum p <= 10^16 + 1000
                     then Just p
                     else Nothing
solve i k p
  | k > length p = let x = div k $ length p
                   in solve i (mod k $ length p) $ map (+x) p
  | otherwise    = let p' = map (flip (-) 1) p
                       p'' = (take i p') ++ [(+(1+length p)) $ p' !! i] ++ drop (i+1) p'
                       m = maximum p''
                       mi = fromJust $ elemIndex m p''
                   in if mi == i && elemIndex (-1) p'' == Nothing
                        then solve (i+1) (k-1) p''
                        else Nothing

f :: Int -> Int -> Maybe [Int]
f k i = let ans = solve 0 k $ make i
        in if ans /= Nothing then ans
                             else f k $ i + 1
