//Ladrilhos - Usando Grafos

#include <stdio.h>
#include <stdlib.h>

typedef struct NoFila{
    int linha;
    int coluna;
    struct NoFila *prox;
}NoFila;

typedef struct Fila{
    NoFila *inicio;
    NoFila *fim;
}Fila;

void iniciar_fila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void entrar_fila(Fila *f, int l, int c){
    NoFila *novo = (NoFila*)malloc(sizeof(NoFila));
    novo->linha = l;
    novo->coluna = c;
    novo->prox = NULL;

    if(f->fim == NULL){
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int fila_vazia(Fila *f){
    return (f->inicio == NULL);
}

void sair_fila(Fila *f, int *l, int *c){
    NoFila *tmp = f->inicio;
    *l = tmp->linha;
    *c = tmp->coluna;

    f->inicio = f->inicio->prox;
    if(f->inicio == NULL)
        f->fim = NULL;

    free(tmp);
}

int main(){
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    int matriz[1010][1010];
    int visitado[1010][1010] = {0};

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int menor_regiao = 1000000000;

    int mov_l[4] = {1, -1, 0, 0};
    int mov_c[4] = {0, 0, 1, -1};

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(!visitado[i][j]){
                int cor = matriz[i][j];
                int tamanho = 0;

                Fila f;
                iniciar_fila(&f);

                entrar_fila(&f, i, j);
                visitado[i][j] = 1;

                while(!fila_vazia(&f)){
                    int l, c;
                    sair_fila(&f, &l, &c);
                    tamanho++;

                    for(int k = 0; k < 4; k++){
                        int nl = l + mov_l[k];
                        int nc = c + mov_c[k];

                        if(nl >= 0 && nl < linhas && nc >= 0 && nc < colunas){
                            if(!visitado[nl][nc] && matriz[nl][nc] == cor){
                                visitado[nl][nc] = 1;
                                entrar_fila(&f, nl, nc);
                            }
                        }
                    }
                }

                if(tamanho < menor_regiao)
                    menor_regiao = tamanho;
            }
        }
    }

    printf("%d\n", menor_regiao);

    return 0;
}
