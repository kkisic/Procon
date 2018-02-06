main = do
  x <- read . concat . words <$> getLine :: IO Int
  let rx = floor . sqrt . realToFrac $ x
  if judge x [1..rx]
    then putStrLn "Yes"
    else putStrLn "No"

judge :: Int -> [Int] -> Bool
judge _ []     = False
judge x (y:ys) = if x == y^2
                   then True
                   else judge x ys
