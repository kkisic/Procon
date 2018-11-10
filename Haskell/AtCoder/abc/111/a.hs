main = interact $ (++ "\n") . map (\x -> if x == '1' then '9' else '1') . init
