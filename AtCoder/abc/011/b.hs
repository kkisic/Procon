import Data.Char
main = interact $ (\x -> (toUpper . head $ x):(map toLower . tail $ x))
