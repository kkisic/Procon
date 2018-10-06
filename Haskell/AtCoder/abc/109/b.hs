import Data.List
main = do
  getLine
  w <- lines <$> getContents
  let double = solve $ sort w
      seq = siritori w
  if double && seq
    then putStrLn "Yes"
    else putStrLn "No"

solve :: [String] -> Bool
solve (_:[]) = True
solve (x:y:ys) = if x == y
                   then False
                   else solve (y:ys)

siritori :: [String] -> Bool
siritori (_:[]) = True
siritori (x:y:ys) = if (last x) == (head y)
                      then siritori (y:ys)
                      else False
