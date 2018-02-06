main = do
  [sx,sy,tx,ty] <- map read . words <$> getLine :: IO [Int]
  let lr = tx - sx
      ud = ty - sy
      ans = (replicate ud 'U') ++
            (replicate lr 'R') ++
            (replicate ud 'D') ++
            (replicate lr 'L') ++
            "L" ++
            (replicate (ud+1) 'U') ++
            (replicate (lr+1) 'R') ++
            "D" ++
            "R" ++
            (replicate (ud+1) 'D') ++
            (replicate (lr+1) 'L') ++ "U"
  putStrLn ans
