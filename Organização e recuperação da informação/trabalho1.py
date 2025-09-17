import pandas as pd
import math
from numpy import dot
from numpy.linalg import norm

# Lista de documentos (cada documento é uma string de palavras-chave)
documents = [
    "Information retrieval systemsMachine learningAccuracyF1-scoreMobile applicationMean reciprocal rankAverage precision",
    "Clinical decision supportPrecision medicineKnowledge basesBayesian inferenceInformation retrieval",
    "Multi-Lingual Information Retrieval (MLIR)Online content availabilitySearch languageLinguistic diversity index",
    "Information RetrievalSemantic Search EngineOntologyTourism",
    "information retrieval systems semantic indexing semantic similarity",
    "information retrieval semantic search engine ontology tourism",
    "information retrieval natural language processing unsupervised classification supervised classification support vector machines",
    "exploratory search information retrieval bag-of-concepts BoC representation software architecture",
    "information retrieval cross language information retrieval multilanguage information retrieval multilingual indian language machine translation",
    "information retrieval system quick response code mobile application smartphone",
    "swarm intelligence ant colony textual data mining medical record processing hospital information system",
    "integrated information retrieval metadata registry schema mapping",
    "domain-specific information retrieval implicit feedback collaborative filtering contextualization of information retrieval",
    "real-time information retrieval sequence analysis entrez BIRAS",
    "analogical inference artificial intelligence cognitive systems communication computers applications fuzzy set theory information retrieval learning systems",
    "pharmacies factors retrieval immunization records IIS",
    "neural information retrieval power distribution graph data operating section similarity matching",
    "clinical information systems intensive care user experience UX",
    "COVID-19 TREC-COVID information retrieval search system taxonomy",
    "HSV color space discrete wavelet transform image retrieval mean average precision"
]

# Pré-processamento: converter para minúsculas e dividir em palavras
documents = [doc.lower().split() for doc in documents]

# Criar um vocabulário único com todas as palavras dos documentos
vocabulary = set()
for doc in documents:
    vocabulary.update(doc)

# Criar dicionários de contagem de palavras para cada documento
word_counts = [dict.fromkeys(vocabulary, 0) for _ in range(len(documents))]
for i, doc in enumerate(documents):
    for word in doc:
        word_counts[i][word] += 1

# Função para calcular o TF (Term Frequency)
def calculate_tf(word_count, doc):
    tf_dict = {}
    doc_length = len(doc)
    for word, count in word_count.items():
        tf_dict[word] = count / float(doc_length)
    return tf_dict

# Calcular o TF para cada documento
tfs = [calculate_tf(word_count, doc) for word_count, doc in zip(word_counts, documents)]

# Função para calcular o IDF (Inverse Document Frequency)
def calculate_idf(documents):
    idf_dict = dict.fromkeys(documents[0].keys(), 0)
    total_docs = len(documents)
    for doc in documents:
        for word, count in doc.items():
            if count > 0:
                idf_dict[word] += 1
    for word, count in idf_dict.items():
        idf_dict[word] = math.log10(total_docs / float(count))
    return idf_dict

# Calcular o IDF para o corpus
idfs = calculate_idf(word_counts)

# Função para calcular o TF-IDF
def calculate_tfidf(tf, idf):
    tfidf = {}
    for word, val in tf.items():
        tfidf[word] = val * idf.get(word, 0)
    return tfidf

# Calcular o TF-IDF para cada documento
tfidfs = [calculate_tfidf(tf, idfs) for tf in tfs]

# Converter para DataFrame para visualização
tfidf_df = pd.DataFrame(tfidfs)
print("TF-IDF dos documentos:")
print(tfidf_df)

# Consulta
query = "information retrieval system"
query_terms = query.lower().split()

# Calcular o TF para a consulta
query_tf = dict.fromkeys(vocabulary, 0)
for word in query_terms:
    if word in query_tf:
        query_tf[word] += 1

# Normalizar o TF da consulta
query_length = len(query_terms)
query_tf_normalized = {word: count / query_length for word, count in query_tf.items()}

# Calcular o TF-IDF para a consulta
query_tfidf = calculate_tfidf(query_tf_normalized, idfs)

# Converter a consulta e os documentos em vetores
query_vector = [query_tfidf.get(word, 0) for word in tfidf_df.columns]
doc_vectors = [tfidf_df.iloc[i].values for i in range(len(tfidf_df))]

# Função para calcular a similaridade do cosseno
def cosine_similarity(vec1, vec2):
    return dot(vec1, vec2) / (norm(vec1) * norm(vec2) + 1e-9)

# Calcular a similaridade entre a consulta e cada documento
similarities = [cosine_similarity(query_vector, doc_vector) for doc_vector in doc_vectors]

# Criar um DataFrame para visualizar os resultados
doc_names = [f"Documento {i+1}" for i in range(len(tfidf_df))]
similarity_df = pd.DataFrame({
    "Documento": doc_names,
    "Similaridade": similarities
})

# Ordenar os documentos por similaridade (do maior para o menor)
similarity_df = similarity_df.sort_values(by="Similaridade", ascending=False)

print("\nRanking de documentos por similaridade com a consulta:")
print(similarity_df)

#matricula: 12021bsi258
#Julio Cesar