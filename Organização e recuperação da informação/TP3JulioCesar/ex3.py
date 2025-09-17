import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import linear_kernel
import time
import nltk
from nltk.stem import PorterStemmer
from preprocessamento import preprocess

ps = PorterStemmer()

def preprocess_stem(text):
    tokens = preprocess(text).split()
    stemmed = [ps.stem(t) for t in tokens]
    return " ".join(stemmed)

with open("musicas.txt", "r", encoding="utf-8") as f:
    lines = [line.strip() for line in f if line.strip()]
docs = [{'id': f'd{i+1}', 'title': line, 'text': line} for i, line in enumerate(lines)]

queries = [
    "música pop romântica",
    "rap americano",
    "balada suave",
    "música eletrônica",
    "colaboração de artistas famosos"
]

corpus_no_stem = [preprocess(d['text']) for d in docs]
corpus_stem = [preprocess_stem(d['text']) for d in docs]

def rank_queries(corpus, queries, docs):
    vect = TfidfVectorizer()
    X = vect.fit_transform(corpus)
    results = []
    times = []
    for q in queries:
        q_proc = preprocess_stem(q) if corpus is corpus_stem else preprocess(q)
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

with pd.ExcelWriter('top5.xls') as writer:
    df_no.to_excel(writer, sheet_name='sem_stemming', index=False)
    df_st.to_excel(writer, sheet_name='com_stemming', index=False)

print(f"Tempo médio SEM stemming: {avg_no:.6f} s")
print(f"Tempo médio COM stemming: {avg_stem:.6f} s")
print("Arquivo top5.xls (com e sem stemming) gerado com sucesso!")
