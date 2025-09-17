from collections import defaultdict
import re

# sample document
document ={
    1: "A digitalização permite registrar, editar, combinar, manipular toda e qualquer informação, por qualquer meio, em qualquer lugar, a qualquer tempo.",
    2: "A digitalização traz a multiplicação de possibilidades de escolha, de interação.",
    3: "A educação presencial está incorporando tecnologias, funções, atividades que eram típicas da educação a distância, e a EAD está descobrindo que pode ensinar de forma menos individualista, mantendo um equilíbrio entre a flexibilidade e a interação.",
}
# Lista de stopwords
stopwords = set([
    "a", "o", "e", "é", "de", "do", "da", "em", "um", "uma", "para", "com", "não", "são", "que", "se", "por", "como", "mas", "está"
])
# function to tokenize and preprocess a document
def preprocess(text):
    text = text.lower()
    tokens = re.findall(r'\w+', text)
    return set(tokens)
# initialize the inverted index
inverted_index = defaultdict(set)
# created the inverted index
for doc_id, doc_text in document.items():
    terms = preprocess(doc_text)
    for term in terms:
        inverted_index[term].add(doc_id)

# Query function
def query(query_text):
    terms = preprocess(query_text)
    results = set(doc_id for term in terms for doc_id in inverted_index.get(term, []))
    return results

# Example query
query_result = query("brown fox")
print("Documents containing 'brown' and 'fox':", query_result)

# Example query
query_result = query("sun shining")
print("Documents containing 'sun' and 'shining':", query_result)
