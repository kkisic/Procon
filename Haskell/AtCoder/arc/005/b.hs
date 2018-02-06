import Data.Array.IO
import Data.Char

type Arr = IOUArray (Int, Int) Int
main = do
  (x,y,w) <- (\[x,y,w] -> (read x, read y, w)) . words <$> getLine :: IO (Int, Int, String)
  num <- concat . map (map digitToInt) . lines <$> getContents
  pass <- newArray ((-2, -2), (12, 12)) 0 :: IO Arr
  let idx = [(i, j) | i <- [1..9], j <- [1..9]]
  initPass pass num idx
  mirrorU pass [(i, j) | i <- [-2..0], j <- [1..9]]
  mirrorD pass [(i, j) | i <- [10..12], j <- [1..9]]
  mirrorL pass [(i, j) | i <- [-2..12], j <- [-2..0]]
  mirrorR pass [(i, j) | i <- [-2..12], j <- [10..12]]
  ans <- solve pass $ position (y, x) w 4
  putStrLn $ map intToDigit $ ans

position :: (Int, Int) -> String -> Int -> [(Int, Int)]
position _      _ 0 = []
position (x, y) s i
  | s == "R" = (x, y) : (position (x, y+1) s $ i-1)
  | s == "L" = (x, y) : (position (x, y-1) s $ i-1)
  | s == "U" = (x, y) : (position (x-1, y) s $ i-1)
  | s == "D" = (x, y) : (position (x+1, y) s $ i-1)
  | s == "RU" = (x, y) : (position (x-1, y+1) s $ i-1)
  | s == "RD" = (x, y) : (position (x+1, y+1) s $ i-1)
  | s == "LU" = (x, y) : (position (x-1, y-1) s $ i-1)
  | s == "LD" = (x, y) : (position (x+1, y-1) s $ i-1)

solve :: Arr -> [(Int, Int)] -> IO [Int]
solve _ [] = return []
solve arr (p:ps) = do
  x <- readArray arr p
  xs <- solve arr ps
  return $ x:xs

initPass :: Arr -> [Int] -> [(Int, Int)] -> IO ()
initPass _ [] [] = return ()
initPass arr (x:xs) (y:ys) = do
  writeArray arr y x
  initPass arr xs ys

mirrorU :: Arr -> [(Int, Int)] -> IO ()
mirrorU _   [] = return ()
mirrorU arr ((x, y):s) = do
  i <- readArray arr (2-x, y)
  writeArray arr (x, y) i
  mirrorU arr s

mirrorD :: Arr -> [(Int, Int)] -> IO ()
mirrorD _   [] = return ()
mirrorD arr ((x, y):s) = do
  i <- readArray arr (18-x, y)
  writeArray arr (x, y) i
  mirrorD arr s

mirrorL :: Arr -> [(Int, Int)] -> IO ()
mirrorL _   [] = return ()
mirrorL arr ((x, y):s) = do
  i <- readArray arr (x, 2-y)
  writeArray arr (x, y) i
  mirrorL arr s

mirrorR :: Arr -> [(Int, Int)] -> IO ()
mirrorR _   [] = return ()
mirrorR arr ((x, y):s) = do
  i <- readArray arr (x, 18-y)
  writeArray arr (x, y) i
  mirrorR arr s
