//Desenhando Labirintos

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int inicio, V, A;
        scanf("%d", &inicio);
        scanf("%d %d", &V, &A);

        int usado[60][60] = {0};
        int i, x, y;
        int qtd_aresta = 0;

        for (i = 0; i < A; i++) {
            scanf("%d %d", &x, &y);

            if (!usado[x][y] && !usado[y][x]) {
                usado[x][y] = usado[y][x] = 1;
                qtd_aresta++;
            }
        }

        printf("%d\n", qtd_aresta * 2);
    }

    return 0;
}
