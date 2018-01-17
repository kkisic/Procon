type Point = (Double, Double)

main = do
  [ax,ay,bx,by] <- map read . words <$> getLine :: IO [Double]
  n <- readLn :: IO Int
  points <- map ((\[x,y] -> (read x, read y)) . words) . lines <$> getContents :: IO [Point]
  let ans = length . filter (==True) . solve (ax, ay) (bx, by) $ points ++ [head points]
  print $ (div ans 2) + 1

solve :: Point -> Point -> [Point] -> [Bool]
solve _ _ (_:[])   = []
solve a b (c:d:ds) = (judge a b c d) : solve a b (d:ds)

judge :: Point -> Point -> Point -> Point -> Bool
judge (ax, ay) (bx, by) (cx, cy) (dx, dy) =
  let ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax)
      tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx)
      tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx)
      td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx)
  in tc * td < 0 && ta * tb < 0;
