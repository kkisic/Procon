import Data.List
main = do
  getLine
  l <- sort . map read . words <$> getLine :: IO [Int]
  if (sum . init $ l) > last l
    then putStrLn "Yes"
    else putStrLn "No"
