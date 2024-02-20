
soma_par :: [Int] -> Int
soma_par [] = 0
soma_par (x:y)
  | par x = x + (soma_par y)
  |otherwise = soma_par y

par :: Int -> Bool
par x = (mod x 2) == 0

soma_termos :: Float -> Float
soma_termos 1 = 1/2
soma_termos n = 1 / (2*n) + soma_termos (n - 1)

fat :: Int -> Int 
fat 0 = 1
fat n = n * fat (n - 1) 

soma_taylor :: Float -> Int -> Float 
soma_taylor x 0 = 1
soma_taylor x n = (x^n/ fromIntegral (fat n)) + soma_taylor x (n-1)

soma_digitos :: Int -> Int
soma_digitos n
  | n == 0 = n
  | otherwise = soma_digitos(n `div`10) + n `mod`10

   