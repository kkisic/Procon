main = do
  n <- readLn :: IO Int
  let d = depth n
  if odd d
    then putStrLn $ oddS 0 1 n
    else putStrLn $ evenS 0 1 n

depth :: Int -> Int
depth n
  | n > 0     = 1 + (depth $ div n 2)
  | otherwise = 0

oddS :: Int -> Int -> Int -> String
oddS 0 n limit
  | n > limit = "Takahashi"
  | otherwise = oddS 1 (n*2+1) limit
oddS 1 n limit
  | n > limit = "Aoki"
  | otherwise = oddS 0 (n*2) limit

evenS :: Int -> Int -> Int -> String
evenS 0 n limit
  | n > limit = "Takahashi"
  | otherwise = evenS 1 (n*2) limit
evenS 1 n limit
  | n > limit = "Aoki"
  | otherwise = evenS 0 (n*2+1) limit
