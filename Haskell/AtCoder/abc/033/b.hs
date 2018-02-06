import Data.List

main = do
  n <- readLn :: IO Int
  input <- sortBy (\x y -> compare (snd x) (snd y)) . map ((\[x,y] -> (x, read y)) . words) . lines <$> getContents :: IO [(String, Int)]
  let all = sum . map snd $ input
  if (div all 2) < (snd . last $ input)
    then putStrLn $ fst . last $ input
    else putStrLn "atcoder"
