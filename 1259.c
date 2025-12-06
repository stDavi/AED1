// Pares e Ímpares - Usando lista encadeada

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
} No;

// Cria lista encadeada a partir de vetor ordenado
No* criar_lista_de_vetor(int v[], int n) {
    No *inicio = NULL, *fim = NULL;
    for(int i=0;i<n;i++){
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = v[i];
        novo->prox = NULL;
        if(inicio == NULL){
            inicio = fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }
    return inicio;
}

// Libera lista
void liberar_lista(No *lista){
    No *aux;
    while(lista){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

// Imprime lista
void imprimir_lista(No *lista){
    No *p = lista;
    while(p){
        printf("%d\n", p->valor);
        p = p->prox;
    }
}

// Comparador para qsort crescente
int cmp_cresc(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}

// Comparador para qsort decrescente
int cmp_decresc(const void *a,const void *b){
    return *(int*)b - *(int*)a;
}

int main(){
    int n;
    scanf("%d",&n);

    int *pares = (int*)malloc(n*sizeof(int));
    int *impares = (int*)malloc(n*sizeof(int));
    int cp=0, ci=0, v;

    for(int i=0;i<n;i++){
        scanf("%d",&v);
        if(v%2==0) pares[cp++]=v;
        else impares[ci++]=v;
    }

    // Ordena
    qsort(pares, cp, sizeof(int), cmp_cresc);
    qsort(impares, ci, sizeof(int), cmp_decresc);

    // Cria listas encadeadas
    No *lista_pares = criar_lista_de_vetor(pares, cp);
    No *lista_impares = criar_lista_de_vetor(impares, ci);

    // Imprime
    imprimir_lista(lista_pares);
    imprimir_lista(lista_impares);

    liberar_lista(lista_pares);
    liberar_lista(lista_impares);

    free(pares);
    free(impares);

    return 0;
}
