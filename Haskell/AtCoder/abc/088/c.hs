import Data.Array.Unboxed
import Data.List

type Arr = UArray (Int, Int) Int

main = do
  c <- map (map read . words) . lines <$> getContents :: IO [[Int]]
  let ans1 = solve c
      ans2 = solve $ transpose c
  if ans1 && ans2
    then putStrLn "Yes"
    else putStrLn "No"

solve :: [[Int]] -> Bool
solve (x:y:[]) = solve' x y
solve (x:y:ys) = if solve' x y
                   then solve (y:ys)
                   else False

solve' :: [Int] -> [Int] -> Bool
solve' x y = (== 1) . length . group $ zipWith (-) x y
