//Frequencia na Aula - Utilizando Arvore

#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore {
    int valor;
    struct NoArvore *esq;
    struct NoArvore *dir;
} NoArvore;

NoArvore* criar_no(int v){
    NoArvore *novo = (NoArvore*)malloc(sizeof(NoArvore));
    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

NoArvore* inserir_na_arvore(NoArvore *raiz, int v, int *inseriu){
    if (raiz == NULL){
        *inseriu = 1;
        return criar_no(v);
    }

    if (v < raiz->valor){
        raiz->esq = inserir_na_arvore(raiz->esq, v, inseriu);
    }
    else if (v > raiz->valor){
        raiz->dir = inserir_na_arvore(raiz->dir, v, inseriu);
    }
    else {
        *inseriu = 0;  // valor repetido
    }

    return raiz;
}

int main(){
    int n, v;
    scanf("%d", &n);

    NoArvore *raiz = NULL;
    int diferentes = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &v);
        int inseriu = 0;
        raiz = inserir_na_arvore(raiz, v, &inseriu);
        if(inseriu) diferentes++;
    }

    printf("%d\n", diferentes);

    return 0;
}
