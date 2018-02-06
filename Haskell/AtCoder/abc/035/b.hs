import qualified Data.ByteString.Char8 as BC
import Data.List

main = do
  s <- map (\x -> (head x, length x)) . group . sort . BC.unpack <$> BC.getLine
  t <- readLn :: IO Int
  let (v, h) = foldl solve (0, 0) s
      (c, x) = head s
      y = if c == '?' then x else 0
      l = (abs v) + (abs h)
  if t == 1
    then print $ l + y
    else if l >= y
           then print $ l - y
           else print $ mod (y - l) 2

solve :: (Int, Int) -> (Char, Int) -> (Int, Int)
solve (v, h) (c, x)
  | c == 'D'  = (v-x, h)
  | c == 'U'  = (v+x, h)
  | c == 'L'  = (v, h-x)
  | c == 'R'  = (v, h+x)
  | otherwise = (v, h)
