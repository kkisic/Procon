import Data.List

main = do
  input <- map (:[]) . sortBy (\x y -> compare (fst x) (fst y)) . map split . tail . lines <$> getContents
  putStr $ unlines . map toTime . foldl1 connect $ input


split :: String -> (Int, Int)
split s = (toBegin . parseInt . take 4 $ s, toEnd . parseInt . drop 5 $ s)

parseInt :: String -> Int
parseInt = read :: String -> Int

toBegin :: Int -> Int
toBegin = (*5) . flip div 5

toEnd :: Int -> Int
toEnd = (*5) . (\x -> if mod x 20 == 12 then x + 8 else x) . (+1) . (flip div 5) . (flip (-) 1)

connect :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
connect x y
  | (snd . last $ x) >= (snd . last $ y) = x
  | (snd . last $ x) >= (fst . last $ y) = (init x) ++ [((fst . last $ x), (snd . last $ y))]
  | otherwise                            = x ++ y

toTime :: (Int, Int) -> String
toTime (x, y) = (toString x) ++ "-" ++ (toString y)

toString :: Int -> String
toString x = if x < 1000
                then (replicate (4 - (length . show $ x)) '0') ++ (show x)
                else show x
