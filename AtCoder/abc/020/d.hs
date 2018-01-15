import Data.Array.Unboxed
import Data.Bits

type Arr = UArray Int Int

modN = 10^9+7

main = do
  [n, k] <- map read . words <$> getLine :: IO [Int]
  let divs = divisor k
      ans = map (\x -> (*k) $ solve (div n (divs !! x)) (div k (divs !! x))) [0..length divs - 1]
  print $ foldl1 (\x y -> flip mod modN $ x + y) ans

divisor :: Int -> [Int]
divisor n = divisor' [1..(floor . sqrt . realToFrac $ n)]
  where divisor' [] = []
        divisor' (i:is) = if mod n i == 0
                            then if div n i /= i
                                   then i : (div n i) : (divisor' is)
                                   else i : (divisor' is)
                            else divisor' is

factorization :: Int -> [Int]
factorization n = f n [2..(floor . sqrt . realToFrac $ n)]
  where f n' [] = if n' == 1
                    then []
                    else [n']
        f n' (i:is) = if mod n' i == 0
                       then i : (f (g n' i) is)
                       else f n' is
        g n'' i
          | mod n'' i == 0 = g (div n'' i) i
          | otherwise      = n''

solve :: Int -> Int -> Int
solve n m =
  let fact = factorization m
      len = length fact
      fArr = listArray (0, len-1) fact :: Arr
      bits = [0..(shiftL 1 len)-1]
  in foldl (solve' fArr n len) 0 bits

solve' :: Arr -> Int -> Int -> Int -> Int -> Int
solve' arr n len ans bit =
  let num = s bit 0
      a = flip mod modN $ div n num
      b = flip mod modN $ flip div 2 $ a * (a+1)
      c = mod num modN
  in if odd $ bitCount bit
       then let sub = flip mod modN $ b * c
            in flip mod modN $ ans - sub + modN
       else flip mod modN $ ans + b * c
  where s bit i
          | i == len  = 1
          | otherwise = if shiftR bit i .&. 1 == 1
                          then (arr ! i) * (s bit $ i + 1)
                          else s bit $ i + 1

bitCount :: Int -> Int
bitCount 0 = 0
bitCount n = n `mod` 2 + bitCount (n `div` 2)
