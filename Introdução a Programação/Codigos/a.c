#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

// declaracao do no da *lista*
typedef struct node Node;
struct node {
    char info;
    Node *next;
};

// declaracao da lista em si
typedef struct lista Lista;
struct lista {
    Node *head;
//    Node *last;
};


Node *newNode(bool *deuCerto)
{
    Node *n;

    n = malloc(sizeof(Node));
    if (n == NULL) *deuCerto = false;
    else *deuCerto = true;

    return n;
}

void deleteNode(Node *n)
{
    if (n != NULL) free(n);
}

Lista *criar(bool *deuCerto)
{
    Lista *L;

    L = malloc(sizeof(Lista));
    if (L == NULL) *deuCerto = false;
    else {
        *deuCerto = true;
        L->head = NULL; // lista vazia
    }

    return L;
}

bool cheia(Lista *L)
{
    return false;
}

bool vazia(Lista *L)
{
    if (L->head == NULL) return true;
    else return false;
}

// Insere de maneira ordenada
void insereOrd(Lista *L, char X, bool *deuCerto)
{
    Node *p, *paux, *pant;
    bool ok;

    p = newNode(&ok); // nao vou tratar o erro se ok == false...
    p->info = X;

    // primeiro caso: lista vazia
    if (vazia(L) == true) {
        p->next = NULL;
        L->head = p;
    } else {
        // segundo caso: X serah o primeiro elemento
        paux = L->head;
        if (p->info < paux->info) {
            p->next = paux;
            L->head = p;
        } else {
            // terceiro caso: nao eh o primeiro
            // procura a posicao na lista
            while (p->info >= paux->info
                    && paux != NULL) {
                // avanca na lista
                pant = paux;
                paux = paux->next;
            }

            if (paux == NULL) {
                // (3.1) X serah o ultimo elemento
                p->next = NULL;
                pant->next = p;
            } else {
                // (3.2) X serah um node intermediario
                p->next = paux;
                pant->next = p;
            }
        }
    }
    *deuCerto = true;
	// No nosso caso, nao temos *deuCerto = false, pois nao tratamos
	//   evetuais erros, como nao ter memoria para alocar um Node.
}

void retira(Lista *L, char X, bool *deuCerto)
{
    Node *p, *anterior;
    bool achou;

    p = L->head; // p = L
    anterior = NULL;

    // avanca na lista
    while ((p != NULL) && (p->info < X)) {
        anterior = p;
        p = p->next;
    }

    if ((p != NULL) && (p->info == X))
        achou = true;
    else achou = false;

    if (achou == true) {
        if (p != L->head) {
            anterior->next = p->next;
            deleteNode(p);
            p = NULL;
            anterior = NULL;
        } else {
            //L->head = L->head->next;
            L->head = p->next;
            deleteNode(p);
            p = NULL;
        } // fim if-else
        *deuCerto = true;
    } else *deuCerto = false;
}

void imprimeTodos(Lista *L)
{
    Node *p;

    p = L->head;

    while (p != NULL) {
        printf("%c ", p->info);
        p = p->next;
    }
    printf("\n");
}

/* Exemplo de funcao para imprimir de maneira recursiva.
 * No nosso exemplo, estamos usando Node cabeca; assim,
 *   precisamos imprimir o conteudo de um Node.
 * Por isso, em vez de termos uma funcao para imprimir lista,
 *   criamos uma para imprimir o Node
 */
void imprimeRec(Node *N)
{
	// caso base, interrompe a funcao.
	if (N == NULL) return;

    printf("%c ", N->info);
    imprimeRec(N->next);
}

/* Agora, fazemos a "interface", uma funcao que chama
 *   a funcao recursiva.
 * Essa eh a funcao que vai para o TAD, a outra eh
 *   apenas uma auxiliar.
 */
void imprime(Lista *L)
{
	Node *p;

	p = L->head;
	imprimeRec(p);
	printf("\n");
}

int main()
{
    Lista *p;
    bool deuCerto;

    p = criar(&deuCerto);
    if (deuCerto == false) {
        printf("Erro ao criar a lista\n");
        exit(1);
    }

    insereOrd(p, '1', &deuCerto);
    insereOrd(p, '2', &deuCerto);
    insereOrd(p, '0', &deuCerto);
    insereOrd(p, '2', &deuCerto);
    insereOrd(p, '1', &deuCerto);
    insereOrd(p, '2', &deuCerto);
    imprime(p);

    retira(p, '1', &deuCerto);
    imprime(p);

    retira(p, '0', &deuCerto);
    imprime(p);


    /*while (!vazia(p)) {
        desempilhar(p, &c, &deuCerto);
        printf("%c\n", c);
    }*/

    return 0;
}