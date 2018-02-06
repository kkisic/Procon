import qualified Data.ByteString.Char8 as BC
import qualified Data.IntMap as M
import Data.List

main = do
  input <- BC.unpack <$> BC.getLine
  let grouped = group . sort $ input
      h = head input
      l = last input
      num = (length input) - 2
  if length grouped == 2
    then putStrLn "Second"
    else if judge h l num then putStrLn "First"
                          else putStrLn "Second"

judge :: Char -> Char -> Int -> Bool
judge h l num
  | h == l    = even num
  | otherwise = odd num
