#include <stdio.h>
#include <stdlib.h>

#define MAX 10010

typedef struct No {
    int v;
    struct No *prox;
} No;

No *adj[MAX];
int cor[MAX];
int ciclo, n, m;

void insere(int u, int v) {
    No *novo = malloc(sizeof(No));
    novo->v = v;
    novo->prox = adj[u];
    adj[u] = novo;
}

void dfs(int v) {
    cor[v] = 1; // CINZA
    for (No *p = adj[v]; p != NULL; p = p->prox) {
        if (cor[p->v] == 1) ciclo = 1;
        else if (cor[p->v] == 0) dfs(p->v);
    }
    cor[v] = 2; // PRETO
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);

        // zera listas e cores
        for (int i = 1; i <= n; i++) {
            cor[i] = 0;
            adj[i] = NULL;
        }

        // lê dependências
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            insere(a, b);
        }

        ciclo = 0;
        for (int i = 1; i <= n && !ciclo; i++)
            if (cor[i] == 0)
                dfs(i);

        printf("%s\n", ciclo ? "SIM" : "NAO");
    }
    return 0;
}
