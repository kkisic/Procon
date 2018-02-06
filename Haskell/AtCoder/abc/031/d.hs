import qualified Data.IntMap as M
import Data.Maybe (fromJust)
import Data.Char

main = do
  [k,n] <- map read . words <$> getLine :: IO [Int]
  input <- map words . lines <$> getContents
  let pattern = getPattern k
      ans = map snd . M.toList . fromJust $ foldSolve input pattern
  putStr $ unlines ans

getPattern :: Int -> [[Int]]
getPattern n = let pattern = [[a,b,c,d,e,f,g,h,i] | i <- z, h <- z, g <- z, f <- z, e <- z, d <- z, c <- z, b <- z, a <- z]
                   z = [1..3]
               in map (take n) $ take (3^n) pattern

foldSolve :: [[String]] -> [[Int]] -> Maybe (M.IntMap String)
foldSolve _  []     = Nothing
foldSolve ss (p:ps) = let im = solve M.empty ss p
                      in if im == Nothing
                           then foldSolve ss ps
                           else im

solve :: M.IntMap String -> [[String]] -> [Int] -> Maybe (M.IntMap String)
solve im []        _   = Just im
solve im ([v,w]:s) spl =
  let vInt = map digitToInt v
      l = map (spl!!) (map (subtract 1) vInt)
  in if length w == sum l
       then let splited = split w l
                im' = update im vInt splited
            in if im' == Nothing
                 then Nothing
                 else solve (fromJust im') s spl
       else Nothing

split :: String -> [Int] -> [String]
split _ []     = []
split s (x:xs) = take x s : split (drop x s) xs

update :: M.IntMap String -> [Int] -> [String] -> Maybe (M.IntMap String)
update im []     []     = Just im
update im (x:xs) (s:ss) = let y = M.lookup x im
                          in if y == Nothing
                               then update (M.insert x s im) xs ss
                               else if s == fromJust y
                                      then update im xs ss
                                      else Nothing
