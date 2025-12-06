//Componentes Conexos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 26

void dfs(int u, int V, int adj[MAXV][MAXV], int visited[], char comp[]) {
    visited[u] = 1;
    comp[u] = 1;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v])
            dfs(v, V, adj, visited, comp);
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int tc = 1; tc <= T; tc++) {
        int V, E;
        scanf("%d %d", &V, &E);

        int adj[MAXV][MAXV] = {0};
        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int u = a - 'a';
            int v = b - 'a';
            adj[u][v] = adj[v][u] = 1;
        }

        int visited[MAXV] = {0};
        int components = 0;

        printf("Case #%d:\n", tc);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                char comp[MAXV] = {0};
                dfs(i, V, adj, visited, comp);

                // imprimir vértices do componente em ordem crescente
                for (int j = 0; j < V; j++) {
                    if (comp[j]) {
                        printf("%c,", 'a' + j);
                    }
                }
                printf("\n");
                components++;
            }
        }

        printf("%d connected components\n\n", components);
    }

    return 0;
}
