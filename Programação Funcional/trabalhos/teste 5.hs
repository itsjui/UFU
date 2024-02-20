{--Nome: Julio Cesar de Jesus Batista--}

{-- Função de ordem superior: (map) e (foldl)--}
formataLinhas :: [(Nome,Preco)] -> String
formataLinhas x = foldl (++) "" (map formataLinha x)

{-- Gera o recibo, Função de ordem superior: (map)--}
geraRecibo :: ListaDeCodigos -> String
geraRecibo a = foldr (++) "" (map formataRecibo [(fazRecibo a)])


{--Função de ordem superior: (foldr)--}
acha :: BaseDeDados -> CodBar -> (Nome,Preco)
acha [] _ = ("item desconhecido", 0)
acha ((o,p,q):xs) x
  |elem j = foldr ((||) . (==o)) False
  |otherwise = acha xs x