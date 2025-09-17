import re

# Abrir e ler o conteúdo do arquivo
with open("hino.txt", "r", encoding= "utf-8") as t:
    texto = t.read()

# tudo em minúsculo
texto = texto.lower()

# Remove pontuação e extrai palavras
palavras = re.findall(r'\b\w+\b', texto)

#sorted organiza as palavras em ordem alfabetica
vocabulario = sorted(set(palavras))

# Exibir resultado
for palavra in vocabulario:
    print(palavra)
