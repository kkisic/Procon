import Data.List
import Control.Monad

main = do
  n <- readLn :: IO Int
  s <- replicateM n getLine
  m <- readLn :: IO Int
  t <- replicateM m getLine
  let ss = map (\x -> (head x, length x)) . group . sort $ s
      tt = map (\x -> (head x, length x)) . group . sort $ t
      point = [0] ++ map (check tt) ss
  print $ maximum point

check :: [(String, Int)] -> (String, Int) -> Int
check [] (s, i) = i
check ((t, j):xx) (s, i) =
  if s == t
    then i - j
    else check xx (s, i)
