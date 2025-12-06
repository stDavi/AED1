//A Biblioteca do Senhor Severino - usaando lista encadeada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char codigo[20];
    struct No *prox;
}No;

No* inserir_ordenado(No *inicio, char *valor){
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->codigo, valor);
    novo->prox = NULL;

    if(inicio == NULL || strcmp(valor, inicio->codigo) < 0){
        novo->prox = inicio;
        return novo;
    }

    No *atual = inicio;
    while(atual->prox != NULL && strcmp(atual->prox->codigo, valor) < 0){
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    return inicio;
}

void liberar_lista(No *inicio){
    No *tmp;
    while(inicio != NULL){
        tmp = inicio;
        inicio = inicio->prox;
        free(tmp);
    }
}

int main(){
    int n;
    char codigo[20];
    int primeiro_caso = 1;

    while(scanf("%d", &n) != EOF){
        No *lista = NULL;

        for(int i = 0; i < n; i++){
            scanf("%s", codigo);
            lista = inserir_ordenado(lista, codigo);
        }

        No *p = lista;

        // NÃO imprimir linha extra antes do primeiro caso
        if(!primeiro_caso){
            // NÃO imprime linha em branco extra entre casos
        }
        primeiro_caso = 0;

        // imprime a lista ordenada
        while(p != NULL){
            printf("%s\n", p->codigo);
            p = p->prox;
        }

        liberar_lista(lista);
    }

    return 0;
}
