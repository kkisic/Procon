import Data.List

main = do
  input <- group . sort . map (rate . (read :: String -> Int)) . words . last . lines <$> getContents
  let isFree = (head . last $ input) == 8
      rank = if isFree
                then (flip (-) 1) . length $ input
                else length input
      free = if isFree
                then length . last $ input
                else 0
  putStr . (++" ") . show $ if rank > 0
                               then rank
                               else 1
  putStrLn . show $ if isFree
                       then rank + free
                       else rank

rate :: Int -> Int
rate x
  | x < 3200  = div x 400
  | otherwise = 8
