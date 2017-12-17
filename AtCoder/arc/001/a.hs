import Data.List
main = putStrLn <$> (\x -> (show . maximum $ x) ++ " " ++ (show . minimum $ x)) . fmap length . (\x -> if length x < 4 then [] : x else x) . group . sort . last . lines =<< getContents
