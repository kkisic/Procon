{-# LANGUAGE BangPatterns #-}
import qualified Data.Sequence as S
import Data.List

type Point = (Double, Double)

eps = 1e-9

main = do
  n <- readLn :: IO Int
  point <- map ((\[x,y] -> (read x, read y)) . words) . lines <$> getContents :: IO [Point]
  let (eq, lt) = foldl' (solve n point) (0, 0) point
      all = div (n*(n-1)*(n-2)) 6
      gt = all*3 - (eq + lt)
  putStrLn $ show (all - eq - gt) ++ " " ++ show eq ++ " " ++ show gt

solve :: Int -> [Point] -> (Int, Int) -> Point -> (Int, Int)
solve n ps (a, b) p =
  let !al = sort $ angleList ps p
      !sl = map (+pi*2) al
      !cl = sort $ inchWorm (head al) S.empty $ al ++ sl
      !(eq, lt) = span (==(-1)) cl
      !eqS = length eq
      !ltS = sum lt
  in (a + eqS, b + ltS)

angleList :: [Point] -> Point -> [Double]
angleList [] _ = []
angleList ((px, py):p) (x, y)
  | px == x && py == y = angleList p (x, y)
  | otherwise =
  let !angle = atan2 (py-y) (px-x)
      !al = angleList p (x, y)
  in angle:al

inchWorm :: Double -> S.Seq Double -> [Double] -> [Int]
inchWorm base que (n:ns)
  | base > pi = []
  | S.length que == 0 = inchWorm n (que S.|> n) ns
  | n-base < (pi/2)-eps = inchWorm base (que S.|> n) ns
  | (pi/2)-eps <= n-base && n-base <= (pi/2)+eps =
  let !(min, que') = dequeue que
  in if que' == S.empty
       then let !ans = inchWorm n que' (n:ns)
            in (-1) : ans
       else let !ans = inchWorm (fst . dequeue $ que') que' (n:ns)
                !len = S.length que'
            in (-1) : len : ans
  | otherwise =
  let !(min, que') = dequeue que
  in if que' == S.empty
       then inchWorm n que' (n:ns)
       else let !ans' = S.length que'
                !ans = seq ans' (inchWorm (fst . dequeue $ que') que' (n:ns))
            in ans' : ans

dequeue :: S.Seq a -> (a, S.Seq a)
dequeue que = case S.viewl que of
                S.EmptyL -> error "Empty Queue"
                x S.:< xs -> (x, xs)
