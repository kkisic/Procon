main = do
  s <- getLine
  putStrLn $ solve s

solve :: String -> String
solve s
  | take 12 s == "WBWBWWBWBWBW" = "Do"
  | take 12 s == "WBWWBWBWBWWB" = "Re"
  | take 12 s == "WWBWBWBWWBWB" = "Mi"
  | take 12 s == "WBWBWBWWBWBW" = "Fa"
  | take 12 s == "WBWBWWBWBWWB" = "So"
  | take 12 s == "WBWWBWBWWBWB" = "La"
  | take 12 s == "WWBWBWWBWBWB" = "Si"
