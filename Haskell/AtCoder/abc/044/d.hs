import Data.Maybe

main = do
  n <- readLn :: IO Int
  s <- readLn :: IO Int
  let rN = floor . sqrt . realToFrac $ n
      rN' = if rN^2 == n then rN - 1 else rN
      ans1 = filter (/=Nothing) $ map (solve n s) [2..rN]
  if n < s
    then print (-1)
    else if length ans1 > 0
           then print $ fromJust $ head ans1
           else let ans2 = map fromJust . filter (/=Nothing) $ map (solve' n s) [1..rN']
                in if length ans2 > 0 && n > s
                     then print $ minimum ans2
                     else if n == s
                            then print $ s+1
                            else print (-1)

f :: Int -> Int -> Int
f b n
  | n < b = n
  | otherwise = (f b $ div n b) + mod n b

solve :: Int -> Int -> Int -> Maybe Int
solve n s b = let ans = f b n
              in if ans == s then Just b
                             else Nothing

solve' :: Int -> Int -> Int -> Maybe Int
solve' n s p = let b = (+1) $ div (n - s) p
               in if b == 1
                    then Nothing
                    else let ans = f b n
                         in if ans == s then Just b
                                        else Nothing
