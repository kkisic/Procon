import Data.List

main = do
  n <- readLn :: IO Integer
  let p = [(a, div n a) | a <- [1..10^5], mod n a == 0]
  putStrLn . show . minimum . map f $ p

f :: (Integer, Integer) -> Int
f (a, b) = max (length . show $ a) $ length . show $ b
