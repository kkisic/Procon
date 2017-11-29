import Control.Monad
import Control.Applicative
import Data.List

data Dir = N | NNE | NE | ENE | E | ESE | SE | SSE | S | SSW | SW | WSW | W | WNW | NW | NNW | C
  deriving Show

type Win = Int

main = do
  input <- getLine
  let win = toWin . (read :: String -> Double) . last . words $ input
      dir = toDir win . (read :: String -> Int) . head . words $ input
  putStrLn $ (show dir) ++ " " ++ (show win)

toDir :: Win -> Int -> Dir
toDir y x
  | y == 0                = C
  | x >= 113  && x < 338  = NNE
  | x >= 338  && x < 563  = NE
  | x >= 563  && x < 788  = ENE
  | x >= 788  && x < 1013 = E
  | x >= 1013 && x < 1238 = ESE
  | x >= 1238 && x < 1463 = SE
  | x >= 1463 && x < 1688 = SSE
  | x >= 1688 && x < 1913 = S
  | x >= 1913 && x < 2138 = SSW
  | x >= 2138 && x < 2363 = SW
  | x >= 2363 && x < 2588 = WSW
  | x >= 2588 && x < 2813 = W
  | x >= 2813 && x < 3038 = WNW
  | x >= 3038 && x < 3263 = NW
  | x >= 3263 && x < 3488 = NNW
  | otherwise             = N

toWin :: Double -> Win
toWin x
  | x >= 0     * 60 && x < 0.25  * 60 = 0
  | x >= 0.25  * 60 && x < 1.55  * 60 = 1
  | x >= 1.55  * 60 && x < 3.35  * 60 = 2
  | x >= 3.35  * 60 && x < 5.45  * 60 = 3
  | x >= 5.45  * 60 && x < 7.95  * 60 = 4
  | x >= 7.95  * 60 && x < 10.75 * 60 = 5
  | x >= 10.75 * 60 && x < 13.85 * 60 = 6
  | x >= 13.85 * 60 && x < 17.15 * 60 = 7
  | x >= 17.15 * 60 && x < 20.75 * 60 = 8
  | x >= 20.75 * 60 && x < 24.45 * 60 = 9
  | x >= 24.45 * 60 && x < 28.45 * 60 = 10
  | x >= 28.45 * 60 && x < 32.65 * 60 = 11
  | otherwise                         = 12
