import Control.Monad
import Data.Array.IO
import Data.List

infinite = maxBound :: Int

main = do
  [n, m] <- map read . words <$> getLine :: IO [Int]
  edge <- (\[x, y, z] -> zip3 x y $ map negate z) . transpose . map (map read . words) . lines <$> getContents :: IO [Edge]
  weight <- newArray (0, n) infinite :: IO Memo
  let index = [1..n*2]
  writeArray weight 0 0
  writeArray weight 1 0
  foldM (bellmanFord edge n n) weight index
  inf <- readArray weight 0
  ans <- readArray weight n
  if inf == 1 then putStrLn "inf"
              else print $ negate ans

type Memo = IOUArray Int Int
type Edge = (Int, Int, Int)

bellmanFord :: [Edge] -> Int -> Int -> Memo -> Int -> IO Memo
bellmanFord edge n dst weight i = do
  b <- readArray weight 0
  case b of
    0 -> do
      foldM (bf' n dst i) weight edge
      return weight
    _ -> do
      return weight

--始点からdstの間にある負閉路を検出(weight[0] = 1)
bf' :: Int -> Int -> Int -> Memo -> Edge -> IO Memo
bf' n dst i weight (from, to, w) = do
  updatable <- readArray weight 0
  case updatable of
    0 -> do
      distFrom <- readArray weight from
      distTo <- readArray weight to
      let isUpdate = distFrom /= infinite && distTo > distFrom + w
          newDist = if isUpdate then distFrom + w
                                else distTo
          isClosed = if isUpdate && i == n && to == dst
                       then 1 else 0
      writeArray weight to newDist
      writeArray weight 0 isClosed
      return weight
    _ -> do
      return weight
