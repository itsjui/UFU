from collections import defaultdict
import re

# Função para carregar o conteúdo do arquivo frases.txt
def load_document(file_path):
    document = {}
    with open(file_path, 'r', encoding='utf-8') as file:
        for line in file:
            # Ignora linhas vazias ou que não contêm ':'
            if ':' not in line:
                continue
            # Extrai o ID e o texto da frase
            doc_id, text = line.strip().split(':', 1)
            document[int(doc_id)] = text.strip()
    return document

# Lista de stopwords
stopwords = set([
    "a", "o", "e", "é", "de", "do", "da", "em", "um", "uma", "para", "com", "não", "são", "que", "se", "por", "como", "mas", "está"
])

# Função para tokenizar e pré-processar um documento
def preprocess(text):
    text = text.lower()
    tokens = re.findall(r'\w+', text)
    # Remove stopwords
    tokens = [token for token in tokens if token not in stopwords]
    return set(tokens)

# Carrega o documento a partir do arquivo frases.txt
document = load_document('frases.txt')

# Inicializa o índice invertido
inverted_index = defaultdict(set)

# Cria o índice invertido
for doc_id, doc_text in document.items():
    terms = preprocess(doc_text)
    for term in terms:
        inverted_index[term].add(doc_id)

# Salvar o índice invertido em um arquivo de texto simples
with open('inverted_index.txt', 'w', encoding='utf-8') as f:
    for term, doc_ids in inverted_index.items():
        f.write(f"{term}: {', '.join(map(str, doc_ids))}\n")

# Função de consulta
def query(query_text):
    terms = preprocess(query_text)
    if not terms:
        return set()
    # Interseção de documentos que contêm todas as palavras
    results = set(inverted_index.get(terms.pop(), set()))
    for term in terms:
        results.intersection_update(inverted_index.get(term, set()))
    return results

# Exemplo de consulta com palavras presentes no documento
query_result = query("digitalização interação")
print("Documentos contendo 'digitalização' e 'interação':", query_result)

# Exemplo de consulta com palavras que não estão no documento
query_result = query("brown fox")
print("Documentos contendo 'brown' e 'fox':", query_result)