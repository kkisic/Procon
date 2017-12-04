main = interact $ flip (++) "\n" . show . minimum . map (read :: String -> Int) . tail . lines
