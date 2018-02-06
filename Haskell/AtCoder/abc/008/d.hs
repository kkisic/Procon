import qualified Data.Map.Strict as M
import Data.List
import Data.Maybe (fromJust)
import Control.Monad

type Memo = M.Map (Point, Point) Int
type Point = (Int, Int)

main = do
  [w,h] <- map read . words <$> getLine :: IO [Int]
  n <- readLn :: IO Int
  p <- map ((\[x,y] -> (read x, read y)) . words) . lines <$> getContents :: IO [(Int, Int)]
  let (ans, memo) = dp p M.empty ((1, 1), (w, h))
  print ans

dp :: [Point] -> Memo -> (Point, Point) -> (Int, Memo)
dp p memo (x, y) =
  let v = M.lookup (x, y) memo
  in if v == Nothing
       then let memo' = foldl' (dp' p (x, y)) memo p
            in (fromJust $ M.lookup (x, y) memo', memo')
       else (fromJust v, memo)

dp' :: [Point] -> (Point, Point) -> Memo -> Point -> Memo
dp' p ((sx, sy), (tx, ty)) memo (x, y) =
  if isIn ((sx, sy), (tx, ty)) (x, y)
    then let (a1, memo1) = dp p memo ((sx, sy), (x-1, y-1))
             (a2, memo2) = dp p memo1 ((x+1, sy), (tx, y-1))
             (a3, memo3) = dp p memo2 ((sx, y+1), (x-1, ty))
             (a4, memo4) = dp p memo3 ((x+1, y+1), (tx, ty))
             c = M.lookup ((sx, sy), (tx, ty)) memo
         in if c == Nothing
              then M.insert ((sx, sy), (tx, ty)) (a1+a2+a3+a4+ty-sy+tx-sx+1) memo4
              else M.insert ((sx, sy), (tx, ty)) (max (a1+a2+a3+a4+ty-sy+tx-sx+1) $ fromJust c) memo4
    else let c = M.lookup ((sx, sy), (tx, ty)) memo
         in if c == Nothing
              then M.insert ((sx, sy), (tx, ty)) 0 memo
              else M.insert ((sx, sy), (tx, ty)) (max 0 $ fromJust c) memo

isIn :: (Point, Point) -> Point -> Bool
isIn ((x1, y1), (x2, y2)) (px, py) =
  x1 <= px && px <= x2 && y1 <= py && py <= y2
