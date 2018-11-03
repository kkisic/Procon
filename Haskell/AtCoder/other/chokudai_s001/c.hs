import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.List

main = do
  n <- getLine
  a <- words <$> getLine
  putStrLn $ f a

f :: [String] -> String
f (x:[]) = x
f (x:xs) = x ++ "," ++ (f xs)
