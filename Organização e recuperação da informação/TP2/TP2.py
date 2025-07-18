import os
import re
import time
import math
from collections import defaultdict, Counter
from sklearn.metrics.pairwise import cosine_similarity
import numpy as np

# Pasta com arquivos .txt
pasta_musicas = os.path.join(os.path.dirname(__file__), "musicas")


# Início do tempo de vocabulário
inicio_vocab = time.time()

# Função para limpar texto
def limpar_texto(texto):
    texto = texto.lower()
    texto = re.sub(r'[^a-záéíóúâêôãõç\s]', '', texto)
    return texto

# Leitura e limpeza
documentos = {}
for nome_arquivo in os.listdir(pasta_musicas):
    if nome_arquivo.endswith(".txt"):
        with open(os.path.join(pasta_musicas, nome_arquivo), "r", encoding="utf-8") as f:
            texto = limpar_texto(f.read())
            documentos[nome_arquivo] = texto.split()

# Construção do vocabulário
vocabulario = set()
for termos in documentos.values():
    vocabulario.update(termos)

fim_vocab = time.time()
tempo_vocab = fim_vocab - inicio_vocab

# Início do tempo de TF-IDF
inicio_tfidf = time.time()

# Cálculo do TF
tfs = {}
for doc, termos in documentos.items():
    contador = Counter(termos)
    total = len(termos)
    tfs[doc] = {termo: contador[termo] / total for termo in contador}

# Cálculo do IDF
idf = {}
N = len(documentos)
for termo in vocabulario:
    df = sum(1 for termos in documentos.values() if termo in termos)
    idf[termo] = math.log(N / (1 + df)) + 1  # +1 para evitar divisão por zero

# Cálculo do TF-IDF
tfidf = {}
for doc, tf in tfs.items():
    tfidf[doc] = {termo: tf[termo] * idf[termo] for termo in tf}

fim_tfidf = time.time()
tempo_tfidf = fim_tfidf - inicio_tfidf

# Tamanho do vocabulário
print(f"Tamanho do vocabulário: {len(vocabulario)}")

# Termo com maior peso TF-IDF
maior_peso = 0
termo_maior = ""
doc_maior = ""
for doc, termos in tfidf.items():
    for termo, peso in termos.items():
        if peso > maior_peso:
            maior_peso = peso
            termo_maior = termo
            doc_maior = doc

print(f"Maior TF-IDF: {maior_peso:.4f} - termo '{termo_maior}' no documento '{doc_maior}'")

# Tempos
print(f"Tempo para criar vocabulário: {tempo_vocab:.4f} segundos")
print(f"Tempo para calcular TF-IDF: {tempo_tfidf:.4f} segundos")

# Consulta de exemplo
consulta = "love you baby"
consulta = limpar_texto(consulta).split()

# Vetor da consulta
tf_consulta = Counter(consulta)
total_consulta = len(consulta)
vetor_consulta = []
for termo in vocabulario:
    tf = tf_consulta[termo] / total_consulta if termo in tf_consulta else 0
    vetor_consulta.append(tf * idf.get(termo, 0))

# Vetores dos documentos
for doc, termos in tfidf.items():
    vetor_doc = [termos.get(termo, 0) for termo in vocabulario]
    similaridade = cosine_similarity([vetor_consulta], [vetor_doc])[0][0]
    print(f"Similaridade da consulta com '{doc}': {similaridade:.4f}")
