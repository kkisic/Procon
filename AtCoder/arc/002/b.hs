import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

main = do
  day <- (\[x,y,z] -> (x,y,z)) . map bsToInt . BC.split '/' <$> BC.getLine :: IO (Int, Int, Int)
  let (y, m, d) = solve day
  printDay $ solve day

printDay :: (Int, Int, Int) -> IO ()
printDay (y, m, d)
  | m < 10 && d < 10 = putStrLn $ show y ++ "/0" ++ show m ++ "/0" ++ show d
  | m < 10 = putStrLn $ show y ++ "/0" ++ show m ++ "/" ++ show d
  | d < 10 = putStrLn $ show y ++ "/" ++ show m ++ "/0" ++ show d
  | otherwise = putStrLn $ show y ++ "/" ++ show m ++ "/" ++ show d

solve :: (Int, Int, Int) -> (Int, Int, Int)
solve x = if judge x
            then x
            else solve $ next x

judge :: (Int, Int, Int) -> Bool
judge (y, m, d) = 0 == (mod y $ m * d)

next :: (Int, Int, Int) -> (Int, Int, Int)
next (y, m, d)
  | d < 28 = (y, m, d+1)
  | elem m [1,3,5,7,8,10,12] && d < 31 = (y, m, d+1)
  | elem m [4,6,9,11] && d < 30 = (y, m, d+1)
  | m == 2 && d < 28 = (y, m, d+1)
  | mod y 400 == 0 && m == 2 && d < 29 = (y, m, d+1)
  | mod y 4 == 0 && mod y 100 /= 0 && m == 2 && d < 29 = (y, m, d+1)
  | m < 12 = (y, m+1, 1)
  | m == 12 = (y+1, 1, 1)

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt
