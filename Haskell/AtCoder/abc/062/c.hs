import Data.List

main = do
  [h, w] <- map read . words <$> getLine :: IO [Int]
  let ws = map (solve h w) [1..w-1]
      hs = map (solve w h) [1..h-1]
  print $ min (minimum ws) (minimum hs)

solve :: Int -> Int -> Int -> Int
solve h w wa = let wb = (w - wa) `div` 2
                   x = wa * h
                   y1 = wb * h
                   z1 = (w - wa - wb) * h
                   y2 = (w - wa) * (h `div` 2)
                   z2 = (w - wa) * ((-) h $ h `div` 2)
                   mi1 = minimum [x, y1, z1]
                   ma1 = maximum [x, y1, z1]
                   mi2 = minimum [x, y2, z2]
                   ma2 = maximum [x, y2, z2]
               in if w - wa >= 2 then min (ma1 - mi1) (ma2 - mi2)
                                 else ma2 - mi2
