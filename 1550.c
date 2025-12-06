//Inversão

#include <stdio.h>
#include <string.h>

int reverte(int x) {// função que inverte os dígitos de x
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int bfs(int A, int B) { // busca em largura
    static int dist[10050];
    static int fila[20050];
    int ini = 0, fim = 0;

    // marca distâncias como -1 (não visitado)
    memset(dist, -1, sizeof(dist));

    dist[A] = 0;
    fila[fim++] = A;

    while (ini < fim) {
        int u = fila[ini++];

        if (u == B) return dist[u];

        // operação +1
        int v = u + 1;
        if (v <= 10000 && dist[v] == -1) {
            dist[v] = dist[u] + 1;
            fila[fim++] = v;
        }

        // operação inverter
        v = reverte(u);
        if (v <= 10000 && dist[v] == -1) {
            dist[v] = dist[u] + 1;
            fila[fim++] = v;
        }
    }

    return -1; // nunca acontece
}

int main() {
    int T, A, B;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }

    return 0;
}
