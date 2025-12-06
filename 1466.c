//Percurso em Árvore por Nível

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *esq;
    struct Nodo *dir;
} Nodo;

/* cria um nodo novo */
Nodo* criar_nodo(int valor) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

/* insere na arvore de busca */
Nodo* inserir_na_arvore(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return criar_nodo(valor);
    }
    if (valor < raiz->valor)
        raiz->esq = inserir_na_arvore(raiz->esq, valor);
    else
        raiz->dir = inserir_na_arvore(raiz->dir, valor);

    return raiz;
}

/* fila simples para BFS */
typedef struct Fila {
    Nodo* itens[600];
    int inicio, fim;
} Fila;

void iniciar_fila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
}

int fila_vazia(Fila* f) {
    return f->inicio == f->fim;
}

void enfileirar(Fila* f, Nodo* n) {
    f->itens[f->fim++] = n;
}

Nodo* desenfileirar(Fila* f) {
    return f->itens[f->inicio++];
}

/* percorre a arvore por nivel (BFS) */
void percurso_por_nivel(Nodo* raiz) {
    Fila f;
    iniciar_fila(&f);

    enfileirar(&f, raiz);

    int primeiro = 1;

    while (!fila_vazia(&f)) {
        Nodo* atual = desenfileirar(&f);

        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esq != NULL) enfileirar(&f, atual->esq);
        if (atual->dir != NULL) enfileirar(&f, atual->dir);
    }
    printf("\n");
}

/* libera memoria da arvore */
void liberar_arvore(Nodo* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {

        int N;
        scanf("%d", &N);

        Nodo* raiz = NULL;

        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            raiz = inserir_na_arvore(raiz, x);
        }

        printf("Case %d:\n", caso);
        percurso_por_nivel(raiz);
        printf("\n");

        liberar_arvore(raiz);
    }

    return 0;
}
