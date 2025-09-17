import re
from math import log
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer

documents = [
    "logan e ororo são x-men",
    "stark parker e logan já foram vingadores parker gostaria de ser novamente",
    "ororo e stark não são guardiões e sim vingadores, groot e rocket são guardiões mas poderiam ser vingadores",
    "eu sou groot logan todos somos groot irá ajudar ororo e os x-men",
    "rocket e groot formam uma boa dupla nos guardiões rocket é mas adora groot"

]

# Abrir e ler o conteúdo do arquivo
documents = [doc.lower().split() for doc in documents]

#sorted organiza as palavras em ordem alfabetica
vocabulario = set()
# Exibir resultado
for doc in documents:
    vocabulario.update(doc)

def termFrequency(term, doc):
    count = 0
    for word in doc:
        if term == word:
            count += 1
    return (1 + log(count, 2))

def inverseTermFrequency(term, documents):
    freq = 0
    #size = N(numero de documentos)
    size = len(documents)
    for doc in documents:
        if term in doc:
            freq += 1
    return log(size/freq, 2)

def tftidfScores(term, documents):
    idf = inverseTermFrequency(term, documents)
    scores = []
