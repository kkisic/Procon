import Control.Monad
main = do
  getLine
  magic <- toTable . concat . map (map (read :: String -> Int) . words) <$> replicateM 10 getLine
  wall <- concat . map (map (read :: String -> Int) . words) . lines <$> getContents
  let index = [[k, i, j] | k <- [0..9], i <- [0..9], j <- [0..9]]
      minMagic = foldl wf magic index
  putStrLn . show . sum . map (solve minMagic) $ wall

toTable :: [Int] -> [(Int, Int, Int)]
toTable = zipWith (\[a, b] x -> (a, b, x)) [[s, t] | s <- [0..9], t <- [0..9]]

readTable :: Int -> Int -> [(Int, Int, Int)] -> Int
readTable x y t = let (_, _, m) = t !! (x * 10 + y) in m

writeTable :: Int -> Int -> Int -> [(Int, Int, Int)] -> [(Int, Int, Int)]
writeTable x y d t = let i = x * 10 + y
                       in take i t ++ [(x, y, d)] ++ drop (i+1) t

wf :: [(Int, Int, Int)] -> [Int] -> [(Int, Int, Int)]
wf t (k:i:j:_) = let d = min (readTable i j t) (readTable i k t + readTable k j t)
                    in writeTable i j d t

solve :: [(Int, Int, Int)] -> Int -> Int
solve t n
  | n == 1 || n == (0-1) = 0
  | otherwise            = readTable n 1 t
