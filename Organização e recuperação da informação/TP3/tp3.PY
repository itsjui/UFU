import re
import string
import unicodedata
import time
import pandas as pd
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import nltk

# Baixar recursos do NLTK
nltk.download('stopwords')

# ==========================
# CONFIGURAÇÕES INICIAIS
# ==========================
# Caminho para a sua coleção de músicas (CSV)
# O CSV deve ter uma coluna chamada "letra" (ou troque pelo nome certo)
caminho_csv = "musicas.csv"
df_musicas = pd.read_csv(caminho_csv)
colecao_documentos = df_musicas["letra"].dropna().tolist()

# Consultas do Ex2
consultas = [
    "amor e paixão",
    "música sertaneja",
    "rock anos 80",
    "tristeza e saudade",
    "alegria e festa"
]

# ==========================
# EX1 – Função de Pré-Processamento
# ==========================
def preprocess(text, use_stemming=False):
    """
    Exercício 1:
    - Converter para minúsculo
    - Remover acentos
    - Remover números
    - Remover pontuação
    - Remover stopwords (NLTK)
    Exercício 3:
    - Se use_stemming=True, aplica o algoritmo de PorterStemmer
    """
    # minúsculas
    text = text.lower()
    # remover acentos
    text = unicodedata.normalize('NFKD', text).encode('ascii', 'ignore').decode('utf-8')
    # remover números
    text = re.sub(r'\d+', '', text)
    # remover pontuação
    text = text.translate(str.maketrans('', '', string.punctuation))
    # tokenizar
    tokens = text.split()
    # remover stopwords
    stop_words = set(stopwords.words('portuguese'))
    tokens = [word for word in tokens if word not in stop_words]
    # aplicar stemming se necessário (Ex3)
    if use_stemming:
        stemmer = PorterStemmer()
        tokens = [stemmer.stem(word) for word in tokens]
    return ' '.join(tokens)

# ==========================
# EX2 e EX3 – Função para rodar consultas e gerar Top 5
# ==========================
def gerar_top5(documentos, consultas, use_stemming=False):
    """
    Exercício 2:
    - Pré-processa documentos e consultas
    - Gera matriz TF-IDF
    - Calcula similaridade (cosine)
    - Retorna Top 5 documentos para cada consulta
    Exercício 4:
    - Mede o tempo para gerar ranking de cada consulta
    """
    # Pré-processar documentos
    docs_processados = [preprocess(doc, use_stemming) for doc in documentos]
    # Criar vetor TF-IDF
    vectorizer = TfidfVectorizer()
    tfidf_matrix = vectorizer.fit_transform(docs_processados)

    resultados = []
    tempos = []

    for consulta in consultas:
        consulta_proc = preprocess(consulta, use_stemming)
        inicio = time.time()
        consulta_vec = vectorizer.transform([consulta_proc])
        similaridades = cosine_similarity(consulta_vec, tfidf_matrix).flatten()
        fim = time.time()
        tempos.append(fim - inicio)
        # Obter índices Top 5
        top5_idx = similaridades.argsort()[-5:][::-1]
        for rank, idx in enumerate(top5_idx, start=1):
            resultados.append({
                "Consulta": consulta,
                "Ranking": rank,
                "Documento": documentos[idx],
                "Score": round(similaridades[idx], 4)
            })
    return pd.DataFrame(resultados), tempos

# ==========================
# EXECUÇÕES
# ==========================
# Sem stemming
df_sem, tempos_sem = gerar_top5(colecao_documentos, consultas, use_stemming=False)
# Com stemming
df_com, tempos_com = gerar_top5(colecao_documentos, consultas, use_stemming=True)

# ==========================
# SALVAR RESULTADOS NO EXCEL (Ex2 e Ex3)
# ==========================
with pd.ExcelWriter("top5.xls") as writer:
    df_sem.to_excel(writer, sheet_name="Sem Stemming", index=False)
    df_com.to_excel(writer, sheet_name="Com Stemming", index=False)

# ==========================
# MÉDIAS DE TEMPO (Ex4)
# ==========================
media_sem = sum(tempos_sem) / len(tempos_sem)
media_com = sum(tempos_com) / len(tempos_com)

print("Tempo médio sem stemming:", round(media_sem, 6), "segundos")
print("Tempo médio com stemming:", round(media_com, 6), "segundos")
print("Planilha top5.xls gerada com sucesso.")
