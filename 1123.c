//Desvio de Rota

#include <stdio.h>
#include <stdlib.h>

#define MAX 250
#define INF 1000000000

typedef struct No {
    int cidade;
    int custo;
    struct No *prox;
} No;

No *adj[MAX];
int distancia[MAX];
int usado[MAX];

void limpar_grafo(int n) {
    int i;
    for (i = 0; i < n; i++) {
        No *p = adj[i];
        while (p != NULL) {
            No *aux = p;
            p = p->prox;
            free(aux);
        }
        adj[i] = NULL;
    }
}

void adicionar_caminho(int a, int b, int custo) {
    No *novo = malloc(sizeof(No));
    novo->cidade = b;
    novo->custo = custo;
    novo->prox = adj[a];
    adj[a] = novo;
}

int menor_caminho(int inicio, int destino, int total) {
    int i;
    for (i = 0; i < total; i++) {
        distancia[i] = INF;
        usado[i] = 0;
    }

    distancia[inicio] = 0;

    while (1) {
        int menor = -1;
        int valor = INF;

        for (i = 0; i < total; i++) {
            if (!usado[i] && distancia[i] < valor) {
                valor = distancia[i];
                menor = i;
            }
        }

        if (menor == -1) break;
        usado[menor] = 1;

        No *p = adj[menor];
        while (p != NULL) {
            int v = p->cidade;
            int novo_custo = distancia[menor] + p->custo;
            if (novo_custo < distancia[v]) {
                distancia[v] = novo_custo;
            }
            p = p->prox;
        }
    }

    return distancia[destino];
}

int main() {
    int N, M, C, K;

    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;

        limpar_grafo(N);

        int i, u, v, p;

        for (i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &p);

            if (u < C && v < C) {
                if (v == u + 1)
                    adicionar_caminho(u, v, p);
                if (u == v + 1)
                    adicionar_caminho(v, u, p);
            }
            else if (u < C && v >= C) {
                adicionar_caminho(v, u, p);
            }
            else if (v < C && u >= C) {
                adicionar_caminho(u, v, p);
            }
            else {
                adicionar_caminho(u, v, p);
                adicionar_caminho(v, u, p);
            }
        }

        int resposta = menor_caminho(K, C - 1, N);
        printf("%d\n", resposta);
    }

    return 0;
}
