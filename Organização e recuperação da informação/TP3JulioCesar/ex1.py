import re
import unicodedata
import nltk
from nltk.corpus import stopwords

# nltk.download('stopwords')  # Executar 1x para baixar
# nltk.download('punkt')      # Executar 1x para baixar

pt_stop = set(stopwords.words('portuguese'))

def remove_accents(text):
    nfkd = unicodedata.normalize('NFKD', text)
    return ''.join([c for c in nfkd if not unicodedata.combining(c)])

def preprocess(text):
    text = text.lower()
    text = remove_accents(text)
    text = re.sub(r'[^a-z\s]', ' ', text)
    tokens = nltk.word_tokenize(text)
    tokens = [t for t in tokens if t not in pt_stop and len(t) > 1]
    return " ".join(tokens)
