# requer: pip install nltk scikit-learn pandas openpyxl
import re
import unicodedata
import time
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import linear_kernel
import nltk
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer

# baixar recursos do NLTK (só precisa rodar 1x)
# nltk.download('punkt')
# nltk.download('stopwords')

# stopwords em português
pt_stop = set(stopwords.words('portuguese'))
ps = PorterStemmer()

def remove_accents(text):
    nfkd = unicodedata.normalize('NFKD', text)
    return ''.join([c for c in nfkd if not unicodedata.combining(c)])

def preprocess(text, do_stem=False):
    text = text.lower()
    text = remove_accents(text)
    # remove números e pontuação
    text = re.sub(r'[^a-z\s]', ' ', text)
    tokens = nltk.word_tokenize(text)
    tokens = [t for t in tokens if t not in pt_stop and len(t) > 1]
    if do_stem:
        tokens = [ps.stem(t) for t in tokens]
    return " ".join(tokens)

# Lendo arquivo txt
with open("musicas.txt", "r", encoding="utf-8") as f:
    lines = [line.strip() for line in f if line.strip()]
docs = [{'id': f'd{i+1}', 'title': line, 'text': line} for i, line in enumerate(lines)]

# Query
queries = [
    "música pop romântica",
    "rap americano",
    "balada suave",
    "música eletrônica",
    "colaboração de artistas famosos"
]

# preparar sem/com stemming
corpus_no_stem = [preprocess(d['text'], do_stem=False) for d in docs]
corpus_stem = [preprocess(d['text'], do_stem=True) for d in docs]

def rank_queries(corpus, queries, docs):
    vect = TfidfVectorizer()
    X = vect.fit_transform(corpus)
    results = []
    times = []
    for q in queries:
        q_proc = preprocess(q, do_stem=(corpus is corpus_stem))
        start = time.perf_counter()
        qv = vect.transform([q_proc])
        sims = linear_kernel(qv, X).flatten()
        top_idx = sims.argsort()[::-1][:5]
        elapsed = time.perf_counter() - start
        times.append(elapsed)
        top5 = [{'rank': i+1,
                 'doc_id': docs[idx]['id'],
                 'title': docs[idx]['title'],
                 'score': float(sims[idx])}
                for i, idx in enumerate(top_idx)]
        results.append({'query': q, 'top5': top5})
    avg_time = sum(times)/len(times) if times else 0.0
    return results, avg_time

# rankings
results_no_stem, avg_no = rank_queries(corpus_no_stem, queries, docs)
results_stem, avg_stem = rank_queries(corpus_stem, queries, docs)

def results_to_df(results):
    rows = []
    for r in results:
        q = r['query']
        for item in r['top5']:
            rows.append({'query': q,
                         'rank': item['rank'],
                         'doc_id': item['doc_id'],
                         'title': item['title'],
                         'score': item['score']})
    return pd.DataFrame(rows)

df_no = results_to_df(results_no_stem)
df_st = results_to_df(results_stem)

# exportar xlsx
with pd.ExcelWriter('top5.xlsx') as writer:
    df_no.to_excel(writer, sheet_name='sem_stemming', index=False)
    df_st.to_excel(writer, sheet_name='com_stemming', index=False)

print(f"Tempo médio por consulta SEM stemming: {avg_no:.6f} s")
print(f"Tempo médio por consulta COM stemming: {avg_stem:.6f} s")
print("Arquivo top5.xlsx gerado com sucesso!")
