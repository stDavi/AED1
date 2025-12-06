//Coloração de Cenários de Jogos

#include <stdio.h>

#define MAX 1024

char imagem[MAX][MAX];
int visitado[MAX][MAX];
int filaX[MAX * MAX], filaY[MAX * MAX];

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {

        // Lê a imagem
        for (int i = 0; i < N; i++)
            scanf("%s", imagem[i]);

        // Zera visitados
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                visitado[i][j] = 0;

        int cliques = 0;

        // Movimentos (4 direções)
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                // Se for um pixel branco não visitado → BFS
                if (imagem[i][j] == '.' && !visitado[i][j]) {
                    cliques++;

                    int ini = 0, fim = 0;
                    filaX[fim] = i;
                    filaY[fim] = j;
                    fim++;
                    visitado[i][j] = 1;

                    while (ini < fim) {
                        int x = filaX[ini];
                        int y = filaY[ini];
                        ini++;

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                                if (!visitado[nx][ny] && imagem[nx][ny] == '.') {
                                    visitado[nx][ny] = 1;
                                    filaX[fim] = nx;
                                    filaY[fim] = ny;
                                    fim++;
                                }
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", cliques);
    }
    return 0;
}
