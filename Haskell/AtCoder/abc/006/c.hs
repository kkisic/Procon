import Data.List
import Data.Maybe

main = do
  input <- map (read :: String -> Int) . words <$> getLine
  let n   = head input
      legs = last input
      ansList = solve n legs
      ans = find (/= Nothing) ansList
  if ans == Nothing
    then putStrLn "-1 -1 -1"
    else putStrLn $ (unwords .  map show . fromJust . fromJust $ ans) ++ " " ++ (show . fromJust $ elemIndex (fromJust ans) ansList)

solve :: Int -> Int -> [Maybe [Int]]
solve n legs = map (\x -> solve' (n-x) $ legs - x * 4) [0..n]

solve' :: Int -> Int -> Maybe [Int]
solve' num remain
  | remain < 0       = Nothing
  | remain == 1      = Nothing
  | remain > num * 3 = Nothing
  | otherwise        = let diff = num * 3 - remain
                           old = num - diff
                       in if diff * 2 + old * 3 == remain && diff <= num
                            then Just [diff, old]
                            else Nothing
