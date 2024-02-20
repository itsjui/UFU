

menor :: [Int] -> Int
menor [x] = x
menor (x:xs) 
  | x < menor xs = x 
  | otherwise = menor xs


menor_de_2 :: Int -> Int-> Int 
menor_de_2 x y 
  | x <= y  = x
  | y <= x = y

digitos :: Int-> [Int]
digitos n 
 | n < 1 = []
 | otherwise = digitos (n `div` 10) ++ [n `mod` 10]

converte:: Int -> [Int]
converte 0 = [0]
converte n
  |n `mod` 2 == 1 = converte (n `div` 2) ++ [1]
  |n `mod` 2 == 0 = converte (n `div` 2) ++ [0]