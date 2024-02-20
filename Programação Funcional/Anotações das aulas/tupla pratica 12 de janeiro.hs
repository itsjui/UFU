Main > qtd_iguais (1,2,3)
0
-}
{  primeira versão

qtd_iguais :: (Int, Int, Int) -> Int

tres_menor :: (Int, Int, Int) -> Int
tres_menor (a,b,c)
	|(a == b) && (a == c) = 3
	|(a == b) || (a == c) || (b == c) = 2
	|otherwise = 0

Main > menor_de_tres (1.5, 1.0, 4.5)
1.0

menor_de_tres :: (Float, Float, Float) -> Float
menor_de_tres (n1, n2,n3)
	|(n1 <= n2) && (n1 <= n3) = n1
	|(n2 >= n1) && (n2 >= n3) = n2
	otherwise = n3