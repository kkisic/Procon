import Data.List
import Data.Maybe

main = do
  s <- getLine
  t <- getLine
  let n = (length s) - (length t)
      tList = makeList n t
      result = map (judge s) tList
      ans = elemIndices True result
  if length ans == 0 then putStrLn "UNRESTORABLE"
                     else putStrLn $ solve ans s tList

makeList :: Int -> String -> [String]
makeList n t = [replicate i '!' ++ t ++ replicate (n-i) '!' | i <- [0..n]]

judge :: String -> String -> Bool
judge [] [] = True
judge (a:as) (b:bs)
  | a == '?'  = judge as bs
  | b == '!'  = judge as bs
  | a == b    = judge as bs
  | otherwise = False

zipAns:: String -> String -> String
zipAns [] [] = []
zipAns (a:as) (b:bs)
 | a == '?' && b == '!' = 'a' : zipAns as bs
 | a == '?'             = b : zipAns as bs
 | b == '!'             = a : zipAns as bs
 | otherwise            = a : zipAns as bs

solve :: [Int] -> String -> [String] -> String
solve ans s t = head . sort . map (\x -> zipAns s $ t !! x) $ ans
