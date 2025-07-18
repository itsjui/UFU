import re

# Abrir e ler o conteúdo do documento
with open("hino.txt", "r", encoding="utf-8") as t:
    texto = t.read().lower()

# Extrair palavras, removendo pontuação
palavras_doc = re.findall(r'\b\w+\b', texto)

# Transformar em conjunto para busca rápida
palavras_doc_set = set(palavras_doc)

# Ler o vocabulário (uma palavra por linha)
with open("vocabulario.txt", "r", encoding="utf-8") as v:
    vocabulario = [linha.strip().lower() for linha in v if linha.strip()]

# Criar vetor Bag of Words
bag_of_words = [1 if palavra in palavras_doc_set else 0 for palavra in vocabulario]

# Exibir resultado
print(bag_of_words)
