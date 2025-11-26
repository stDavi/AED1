#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *fila = (int*) malloc(N * sizeof(int));
    int presente[10001] = {0}; 

    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        presente[x] = 1;
    }

    int first = 1;
    for (int i = 0; i < N; i++) {
        if (presente[fila[i]]) {
            if (!first) printf(" ");
            printf("%d", fila[i]);
            first = 0;
        }
    }

    printf("\n");

    free(fila);
    return 0;
}
