//Jogando Cartas Fora

#include <stdio.h>

void simular_jogo(int n) {
    int fila[100], inicio = 0, fim = 0;
    int descartadas[100], qtd_descartadas = 0;

    int i;

    for (i = 1; i <= n; i++) {
        fila[fim++] = i;
    }

    while (fim - inicio > 1) {
        descartadas[qtd_descartadas++] = fila[inicio++];
        fila[fim++] = fila[inicio++];
    }

    printf("Discarded cards:");
    for (i = 0; i < qtd_descartadas; i++) {
        if (i == 0)
            printf(" %d", descartadas[i]);
        else
            printf(", %d", descartadas[i]);
    }
    printf("\n");

    printf("Remaining card: %d\n", fila[inicio]);
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        simular_jogo(n);
    }

    return 0;
}
