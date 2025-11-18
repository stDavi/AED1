#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore binária
typedef struct Node {
    int altura;
    struct Node *esq, *dir;
} Node;

// Função para criar um novo nó
Node* novoNo(int altura) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->altura = altura;
    n->esq = n->dir = NULL;
    return n;
}

// Função para inserir um valor na árvore binária
Node* inserir(Node* raiz, int altura) {
    if (raiz == NULL)
        return novoNo(altura);

    if (altura < raiz->altura)
        raiz->esq = inserir(raiz->esq, altura);
    else
        raiz->dir = inserir(raiz->dir, altura);

    return raiz;
}

// Função para percorrer a árvore em ordem (in-order traversal)
void imprimirOrdenado(Node* raiz, int *primeiro) {
    if (raiz == NULL)
        return;

    imprimirOrdenado(raiz->esq, primeiro);

    if (!(*primeiro))
        printf(" ");
    printf("%d", raiz->altura);
    *primeiro = 0;

    imprimirOrdenado(raiz->dir, primeiro);
}

// Função para liberar a memória da árvore
void liberar(Node* raiz) {
    if (raiz == NULL)
        return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);

        Node* raiz = NULL;

        for (int i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            raiz = inserir(raiz, h);
        }

        int primeiro = 1;
        imprimirOrdenado(raiz, &primeiro);
        printf("\n");

        liberar(raiz);
    }

    return 0;
}
