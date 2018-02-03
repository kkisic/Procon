import System.IO

main = do
  n <- readLn :: IO Int
  s <- query 0
  ans <- upperBound s 0 n
  print ans

--[lb, ub)
upperBound :: Int -> Int -> Int -> IO Int
upperBound s lb ub
  | ub - lb == 1 = return lb
  | otherwise = do
    let mid = div (lb + ub) 2
        s' = if (odd $ mid - lb) then negate s else s
    flag <- judge s lb mid
    if flag
      then upperBound s' mid ub
      else upperBound s lb mid

judge :: Int -> Int -> Int -> IO Bool
judge s l x = do
  m <- query x
  if odd $ x-l
    then return $ s /= m
    else return $ s == m

query :: Int -> IO Int
query i = do
  putStrLn $ show i
  hFlush stdout
  s <- getLine
  case s of
    "Vacant" -> return 0
    "Male" -> return 1
    "Female" -> return $ negate 1
