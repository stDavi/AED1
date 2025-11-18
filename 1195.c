#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *esq, *dir;
} Node;

// Cria novo nó
Node* novoNo(int valor) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->valor = valor;
    n->esq = n->dir = NULL;
    return n;
}

// Insere na árvore binária de busca
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL)
        return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Percurso pré-ordem
void preOrdem(Node* raiz, int *primeiro) {
    if (raiz == NULL) return;
    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;
    preOrdem(raiz->esq, primeiro);
    preOrdem(raiz->dir, primeiro);
}

// Percurso em-ordem
void inOrdem(Node* raiz, int *primeiro) {
    if (raiz == NULL) return;
    inOrdem(raiz->esq, primeiro);
    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;
    inOrdem(raiz->dir, primeiro);
}

// Percurso pós-ordem
void posOrdem(Node* raiz, int *primeiro) {
    if (raiz == NULL) return;
    posOrdem(raiz->esq, primeiro);
    posOrdem(raiz->dir, primeiro);
    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;
}

// Libera memória da árvore
void liberar(Node* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        int N;
        scanf("%d", &N);

        Node* raiz = NULL;
        for (int i = 0; i < N; i++) {
            int v;
            scanf("%d", &v);
            raiz = inserir(raiz, v);
        }

        printf("Case %d:\n", caso);

        int primeiro = 1;
        printf("Pre.: ");
        preOrdem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        inOrdem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        posOrdem(raiz, &primeiro);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
