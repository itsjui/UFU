{--Nome: Julio Cesar de Jesus Batista --}

{--função para inverter a lista --}

toDigitsReverso :: Integer -> [Integer]
toDigitsReverso n 
  |n < 0 = []
  |n < 10 = [ n ]
  |otherwise = mod n 10 : toDigitsReverso (div n 10)

----------------------------------------------------------------------
{--Transforma a entrada em uma lista--}

toDigits :: Integer -> [Integer]
toDigits n = reverse (toDigitsReverso n)

----------------------------------------------------------------------
{--Duplica o segundo elemento de cada lista--}
doubleEveryOther' :: [Integer] -> [Integer]
doubleEveryOther' [] = []
doubleEveryOther' [x] = [x]
doubleEveryOther' (x:y:resto) = x : 2*y : doubleEveryOther' resto

----------------------------------------------------------------------
{--Duplica o segundo elemento da lista invertida--}
doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther lista = reverse (doubleEveryOther' (reverse lista))

----------------------------------------------------------------------
{--Soma todos os digitos--}
sumDigits :: [Integer] -> Integer
sumDigits [] = 0
sumDigits (n:ns) 
  |n < 10 = n + sumDigits ns
  |otherwise = div n 10 + mod n 10 + sumDigits ns

----------------------------------------------------------------------
{--Valida o cartão de credito--}
validate :: Integer -> Bool
validate num = mod (sumDigits (doubleEveryOther (toDigits num))) 10 == 0