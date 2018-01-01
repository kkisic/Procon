import Data.List
main = putStrLn <$> show . (\x -> head x - last x) . fmap read . lines =<< getContents
