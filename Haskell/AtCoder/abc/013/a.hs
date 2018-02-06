import Data.List
main = putStrLn <$> show . (+1) . head . (flip elemIndices $ ["A", "B", "C", "D", "E"]) =<< getLine
