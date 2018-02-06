import Data.Array.IO
import Data.Bits
import Data.List
import Control.Monad

type Arr = IOUArray Int Int
type Choco = (Int, Int, Int)

main = do
  [n,m,p,q,r] <- map read . words <$> getLine :: IO [Int]
  input <- map (\[x,y,z] -> (x,y,z)) . map (map read . words) . lines <$> getContents :: IO [Choco]
  let girl = [i | i <- [1..2^n-1], popCount i == p]
  ans <- mapM (solve input m q) girl
  print $ maximum ans

solve :: [Choco] -> Int -> Int -> Int -> IO Int
solve choco m q girl = do
  let need = filterBoy choco girl
  boy <- newArray (1, m) 0 :: IO Arr
  foldM happiness boy need
  h <- getElems boy
  return $ sum . take q . sortBy (\x y -> compare y x) $ h

happiness :: Arr -> Choco -> IO Arr
happiness boy (_, y, z) = do
  x <- readArray boy y
  writeArray boy y $ x + z
  return boy

filterBoy :: [Choco] -> Int -> [Choco]
filterBoy []           _    = []
filterBoy ((x,y,z):cs) girl =
  if shiftR girl (x-1) .&. 1 == 1
    then (x,y,z) : filterBoy cs girl
    else filterBoy cs girl
