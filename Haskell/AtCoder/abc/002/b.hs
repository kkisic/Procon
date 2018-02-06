import Control.Monad
import Control.Applicative
import Data.List

main = putStrLn <$> filter (\x -> x /= 'a' && x /= 'i' && x /= 'u' && x /= 'e' && x /= 'o') =<< getLine
