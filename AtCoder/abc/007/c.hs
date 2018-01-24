import qualified Data.ByteString.Char8 as BC
import qualified Data.Sequence as S
import Data.Maybe (fromJust)
import Data.List
import Data.Array.IO
import Control.Monad

type ArrC = IOUArray (Int, Int) Char
type Arr = IOUArray (Int, Int) Int
type Queue = S.Seq (Int, Int)

main = do
  [r, c] <- map read . words <$> getLine :: IO [Int]
  [sy, sx] <- map read . words <$> getLine :: IO [Int]
  [gy, gx] <- map read . words <$> getLine :: IO [Int]
  cc <- concat <$> get2DListBC
  area <- newListArray ((1, 1), (r, c)) cc :: IO ArrC
  depth <- newArray ((1, 1), (r, c)) 0 :: IO Arr
  bfs area depth $ S.singleton (sy, sx)
  ans <- readArray depth (gy, gx)
  print ans

bfs :: ArrC -> Arr -> Queue -> IO ()
bfs area depth que
  | S.length que == 0 = return ()
  | otherwise = do
    let (y, x) = fst . dequeue $ que
        que' = S.drop 1 que
    d <- readArray depth (y, x)
    que'' <- foldM (enqueue area depth (d+1)) que' [(y, x+1), (y, x-1), (y+1, x), (y-1, x)]
    bfs area depth que''

enqueue :: ArrC -> Arr -> Int -> Queue -> (Int, Int) -> IO Queue
enqueue area depth dd que pos = do
  c <- readArray area pos
  d <- readArray depth pos
  if c == '.' && d == 0
    then do
      writeArray depth pos $ dd
      return $ que S.|> pos
    else return que


dequeue :: S.Seq a -> (a, S.Seq a)
dequeue que = case S.viewl que of
                S.EmptyL -> error "Empty Queue"
                x S.:< xs -> (x, xs)
  
bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

get2DListBC :: IO [String]
get2DListBC = map BC.unpack . BC.lines <$> BC.getContents
