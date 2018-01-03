import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type Image = IOUArray (Int, Int) Char

main = do
  [h,w] <- map read . words <$> getLine :: IO [Int]
  image <- concat <$> replicateM h getLine
  before <- newListArray ((1, 1), (h, w)) image :: IO Image
  after <- newArray ((1, 1), (h, w)) '.' :: IO Image
  after' <- newArray ((1, 1), (h, w)) '.' :: IO Image
  let idx = [(i, j) | i <- [1..h], j <- [1..w]]
  foldM (decode h w before) after idx
  foldM (encode h w after) after' idx
  ans <- toImage w <$> getElems after
  encoded <- getElems after'
  if encoded == image
    then do
      putStrLn "possible"
      putStr $ unlines ans
    else do
      putStrLn "impossible"

decode :: Int -> Int -> Image -> Image -> (Int, Int) -> IO Image
decode h w before after (i, j) = do
  cl <- mapM uncontraction [(ii, jj) | ii <- [i-1..i+1], jj <- [j-1..j+1]]
  if cl == "#########"
    then do
      writeArray after (i, j) '#'
      return after
    else do
      writeArray after (i, j) '.'
      return after
  where uncontraction :: (Int, Int) -> IO Char
        uncontraction (i', j')
          | 1 <= i' && i' <= h && 1 <= j' && j' <= w = do
            c <- readArray before (i', j')
            return c
          | otherwise = return '#'

encode :: Int -> Int -> Image -> Image -> (Int, Int) -> IO Image
encode h w before after (i, j) = do
  c <- readArray before (i, j)
  if c == '#'
    then do
      foldM contraction after [(ii, jj) | ii <- [i-1..i+1], jj <- [j-1..j+1]]
      return after
    else do
      return after
  where contraction :: Image -> (Int, Int) -> IO Image
        contraction after (i', j')
          | 1 <= i' && i' <= h && 1 <= j' && j' <= w = do
            writeArray after (i', j') '#'
            return after
          | otherwise = return after

toImage :: Int -> String -> [String]
toImage _ [] = []
toImage w s = (take w s) : (toImage w $ drop w s)
