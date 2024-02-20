--Codigos Lista 1 
--Aluno: Julio Cesar de Jesus Batista
--Matricula: 12021BSI258

terceiro :: Int -> Int
terceiro x = head(tail(tail (x))

ultimo :: String -> Char
ultimo x = head(reverse(x))

inicio :: [Char] -> [Char]
inicio x = reverse(tail(reverse x))

iniciais :: String -> String -> (Char, Char)
iniciais inicialA inicialB = (head inicialA, head inicialB)