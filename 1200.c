#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char valor;
    struct node *esq, *dir;
} Node;

Node* novoNo(char v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->valor = v;
    n->esq = n->dir = NULL;
    return n;
}

Node* inserir(Node* raiz, char v) {
    if (raiz == NULL) return novoNo(v);
    if (v < raiz->valor)
        raiz->esq = inserir(raiz->esq, v);
    else
        raiz->dir = inserir(raiz->dir, v);
    return raiz;
}

int buscar(Node* raiz, char v) {
    if (raiz == NULL) return 0;
    if (raiz->valor == v) return 1;
    if (v < raiz->valor) return buscar(raiz->esq, v);
    return buscar(raiz->dir, v);
}

void infixa(Node* raiz, int *primeiro) {
    if (raiz == NULL) return;
    infixa(raiz->esq, primeiro);
    if (!(*primeiro)) printf(" ");
    printf("%c", raiz->valor);
    *primeiro = 0;
    infixa(raiz->dir, primeiro);
}

void prefixa(Node* raiz, int *primeiro) {
    if (raiz == NULL) return;
    if (!(*primeiro)) printf(" ");
    printf("%c", raiz->valor);
    *primeiro = 0;
    prefixa(raiz->esq, primeiro);
    prefixa(raiz->dir, primeiro);
}

void posfixa(Node* raiz, int *primeiro) {
    if (raiz == NULL) return;
    posfixa(raiz->esq, primeiro);
    posfixa(raiz->dir, primeiro);
    if (!(*primeiro)) printf(" ");
    printf("%c", raiz->valor);
    *primeiro = 0;
}

int main() {
    Node* raiz = NULL;
    char comando[20], letra;

    while (scanf("%s", comando) != EOF) {
        
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &letra);
            raiz = inserir(raiz, letra);
        }

        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &letra);
            if (buscar(raiz, letra))
                printf("%c existe\n", letra);
            else
                printf("%c nao existe\n", letra);
        }

        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        }

        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        }

        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
    }

    return 0;
}
