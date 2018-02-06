import System.IO

main = do
  n <- readLn :: IO Int
  (d1, v1) <- maximum . flip zip [2..n] <$> mapM (query 1) [2..n]
  let vertex = [i | i <- [1..n], i /= v1]
  (d2, v2) <- maximum . flip zip vertex <$> mapM (query v1) vertex
  putStrLn $ "! " ++ show d2

query :: Int -> Int -> IO Int
query x y = do
  putStrLn $ "? " ++ show x ++ " " ++ show y
  hFlush stdout
  return =<< readLn :: IO Int
