import Data.Maybe

main = do
  input <- getLine
  let ans = solve 1 input
  if ans == Nothing then putStrLn "-1 -1"
                    else putStrLn $ (\(x, y) -> show x ++ " " ++ show y) . fromJust $ ans

solve :: Int -> String -> Maybe (Int, Int)
solve n [] = Nothing
solve n (a:[]) = Nothing
solve n (a:b:[])
  | a == b = Just (n, n+1)
  | otherwise = Nothing
solve n (a:b:c:cs)
  | a == b || a == c || b == c = Just (n, n+2)
  | otherwise                  = solve (n+1) (b:c:cs)
