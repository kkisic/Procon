import Data.Char
import Data.List

main = do
  input <- map digitToInt <$> getLine
  let f = [(+), (-)]
      func = [[a, b, c] | a <- f, b <- f, c <- f]
      fS = ["+", "-"]
      funcS = [[a, b, c] | a <- fS, b <- fS, c <- fS]
      n = map show input
  putStrLn $ (\x -> toString n (funcS !! x)) . head . elemIndices 7 . map (solve input) $ func

solve :: [Int] -> [Int -> Int -> Int] -> Int
solve (n:ns) [] = n
solve (n:m:ms) (f:fs) = solve ((f n m):ms) fs

toString :: [String] -> [String] -> String
toString n f = (n!!0) ++ (f!!0) ++ (n!!1) ++ (f!!1) ++ (n!!2) ++ (f!!2) ++ (n!!3) ++ "=7"
