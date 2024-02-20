{--Julio Cesar de Jesus Batista--}
{-- Produção de Um Recibo Fiscal em um Supermecado--}

type Nome = String
type Preco = Int
type Codigo = Int
type Recibo = [(Nome,Preco)]
type CodBar = [Codigo]
type BaseDeDados = [(Codigo,Nome,Preco)]
type Produtos = BaseDeDados
type Carrinho = [Codigo]

-- Lista de Produtos Catalogados --

listaDeProdutos :: BaseDeDados

listaDeProdutos = [(1234, "Oleo DoBom, 1l" , 195), (4756, "Chocolate Cazzeiro, 250g" , 180), (3216, "Arroz DoBom, 5Kg", 213), (5823, "Balas Pedregulho, 1Kg" , 379), (4719, "Queijo Mineirim, 1Kg" , 449), (6832, "Iogurte Maravilha, 1Kg" , 499), (1112, "Rapadura QuebraDente, 1Kg", 80), (1111, "Sal Donorte, 1Kg", 221), (1113, "Cafe DoBom, 1Kg", 285), (1115, "Biscoito Bibi, 1Kg", 80), (3814, "Sorvete QGelo, 1l", 695)] 


-- Formatações -- 


-- formataCentavos -- 


formataCentavos :: Preco -> String
formataCentavos x = show (x `div` 100) ++ "." ++ show (x `mod` 100)


soma :: [Int] -> Int
soma [x] = x
soma (x:xs) = x+soma xs 


-- formataLinha --


formataLinha :: (Nome,Preco) -> String
formataLinha (n,p) = n ++ formataLinha2(formataLinha1(n,p)) ++ formataCentavos p ++ "\n"


formataRecibo :: Recibo -> String
formataRecibo r = "\nSupermercado QLegal\n"++fazRecibo2(r) ++ total(geralTotal(r)) 


formataLinha1 :: (Nome,Preco) -> Int
formataLinha1 (n,p) = tamanhoLinha -(length(n) + length(show(p)))


formataLinha2 :: Int -> String
formataLinha2 0 = ""
formataLinha2 n = replicate n '.'


tamanhoLinha :: Int
tamanhoLinha = 30

total :: Preco -> String
total x = formataLinha("Total",x)



-- Gera Informações --


geralTotal :: Recibo -> Preco
geralTotal a = soma(alterar(a))


fazRecibo :: CodBar -> Recibo
fazRecibo [] = []
fazRecibo (x:xs) = fazRecibo1(x):fazRecibo(xs)


fazRecibo1 :: Codigo -> (Nome,Preco)
fazRecibo1 cod = achaItem listaDeProdutos cod


fazRecibo2 :: Recibo -> String 
fazRecibo2 [] = ""
fazRecibo2 (x:xs) =  formataLinha(x) ++ fazRecibo2 xs


geraRecibo :: CodBar -> String
geraRecibo lc = formataRecibo(fazRecibo lc)



-- Procura Item do Catalogo -- 

achaItem :: BaseDeDados -> Codigo -> (Nome,Preco)
achaItem [] codigo = ("Item não catalogado",0)
achaItem ((a,b,c):xs) codigo
  |a == codigo = (b,c)
  |otherwise = achaItem xs codigo



alterar :: Recibo -> [Int]
alterar recibo = [ pegaPreco x | x <- recibo]
  |where
  |pegaPreco (a,b) = b



-- Final

main = putStrLn (geraRecibo([1234,3216,4719,1112,1113,3814,1234]))