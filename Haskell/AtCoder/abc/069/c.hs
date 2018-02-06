import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

main = do
  n <- readLn :: IO Int
  input <- getIntListBC
  let mul4 = length . filter (\x -> 0 == mod x 4) $ input
      odds = length . filter (\x -> 0 /= mod x 2) $ input
      mul2 = n - (mul4 + odds)
  if judge mul2 mul4 odds then putStrLn "Yes"
                          else putStrLn "No"

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

judge :: Int -> Int -> Int -> Bool
judge m2 m4 o = m2 == 0 && o <= m4 + 1 || o <= m4
