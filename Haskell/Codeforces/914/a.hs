import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List
import Control.Applicative
import Control.Monad

main = do
  n <- readLn :: IO Int
  a <- sortBy (\x y -> compare y x) <$> getIntListBC
  print $ solve a

solve :: [Int] -> Int
solve (x:xs) = let y = floor . sqrt $ realToFrac x
               in if x == y^2
                    then solve xs
                    else x

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine
