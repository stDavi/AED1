#include <stdio.h>

#define MAX 10010
int mat[MAX][MAX];
int cor[MAX];
int ciclo, n, m;

void dfs(int v) {
    cor[v] = 1; // CINZA
    for (int i = 1; i <= n; i++) {
        if (mat[v][i]) {
            if (cor[i] == 1) 
                ciclo = 1;
            else if (cor[i] == 0) 
                    dfs(i);
        }
    }
    cor[v] = 2; // PRETO
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);

        // zera matriz e cores
        for (int i = 1; i <= n; i++) {
            cor[i] = 0;
            for (int j = 1; j <= n; j++)
                mat[i][j] = 0;
        }

        // lê dependências
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            mat[a][b] = 1;
        }

        ciclo = 0;
        for (int i = 1; i <= n && !ciclo; i++)
            if (cor[i] == 0)
                dfs(i);

        printf("%s\n", ciclo ? "SIM" : "NAO");
    }
    return 0;
}
