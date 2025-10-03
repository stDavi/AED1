#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, menor, posicao;
    int *vetor;

    scanf("%d", &N);

    // aloca dinamicamente um vetor de N inteiros
    vetor = (int *) malloc(N * sizeof(int));

    if (vetor == NULL) {
        return 1; // erro na alocação
    }

    for (i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    menor = vetor[0];
    posicao = 0;

    for (i = 1; i < N; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    // libera a memória
    free(vetor);

    return 0;
}
