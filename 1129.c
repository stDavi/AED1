//Leitura Ótica - usando fila

#include <stdio.h>

#define TAM 10

typedef struct {
    int dados[TAM];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void iniciar_fila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

void inserir_fila(Fila *f, int valor) {
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM;
    f->quantidade++;
}

int remover_fila(Fila *f) {
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->quantidade--;
    return valor;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (n--) {

            Fila fila;
            iniciar_fila(&fila);

            int valor;

            // Lendo 5 valores e colocando na fila
            for (int i = 0; i < 5; i++) {
                scanf("%d", &valor);
                inserir_fila(&fila, valor);
            }

            int posicao = -1; 
            int contador_pretas = 0;

            // Processando fila
            for (int i = 0; i < 5; i++) {
                int leitura = remover_fila(&fila);

                if (leitura <= 127) {
                    contador_pretas++;
                    posicao = i;
                }
            }

            if (contador_pretas == 1) {
                char respostas[5] = {'A','B','C','D','E'};
                printf("%c\n", respostas[posicao]);
            } else {
                printf("*\n");
            }
        }
    }

    return 0;
}


