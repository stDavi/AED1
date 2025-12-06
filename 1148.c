#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 500

typedef struct No {
    int destino, peso;
    struct No *prox;
} No;

typedef struct {
    int cidade, dist;
} ItemHeap;

typedef struct {
    ItemHeap *v;
    int tam;
} MinHeap;

No *grafo[MAX + 1];
int temAresta[MAX + 1][MAX + 1];  // matriz para detectar reciprocidade
int dist[MAX + 1], usado[MAX + 1];


// --------------------------------------------
// Criar nó
// --------------------------------------------
void adicionar_aresta(int u, int v, int peso) {
    No *novo = (No*) malloc(sizeof(No));
    novo->destino = v;
    novo->peso = peso;
    novo->prox = grafo[u];
    grafo[u] = novo;
}


// --------------------------------------------
// Min-heap simples
// --------------------------------------------
void trocar(ItemHeap *a, ItemHeap *b) {
    ItemHeap t = *a;
    *a = *b;
    *b = t;
}

MinHeap* criar_heap() {
    MinHeap *h = (MinHeap*) malloc(sizeof(MinHeap));
    h->v = (ItemHeap*) malloc(sizeof(ItemHeap) * (MAX * MAX + 5));
    h->tam = 0;
    return h;
}

void inserir(MinHeap *h, int cidade, int dist) {
    int i = ++h->tam;
    h->v[i].cidade = cidade;
    h->v[i].dist = dist;

    while (i > 1 && h->v[i].dist < h->v[i/2].dist) {
        trocar(&h->v[i], &h->v[i/2]);
        i /= 2;
    }
}

ItemHeap remover(MinHeap *h) {
    ItemHeap topo = h->v[1];
    h->v[1] = h->v[h->tam--];

    int i = 1;
    while (1) {
        int e = 2*i, d = e + 1, menor = i;

        if (e <= h->tam && h->v[e].dist < h->v[menor].dist) menor = e;
        if (d <= h->tam && h->v[d].dist < h->v[menor].dist) menor = d;

        if (menor == i) break;

        trocar(&h->v[i], &h->v[menor]);
        i = menor;
    }
    return topo;
}


// --------------------------------------------
// Dijkstra
// --------------------------------------------
void dijkstra(int inicio) {
    MinHeap *h = criar_heap();

    for (int i = 1; i <= MAX; i++) {
        dist[i] = INT_MAX;
        usado[i] = 0;
    }

    dist[inicio] = 0;
    inserir(h, inicio, 0);

    while (h->tam > 0) {
        ItemHeap atual = remover(h);
        int u = atual.cidade;

        if (usado[u]) continue;
        usado[u] = 1;

        for (No *p = grafo[u]; p != NULL; p = p->prox) {
            int v = p->destino;
            int peso = p->peso;

            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                inserir(h, v, dist[v]);
            }
        }
    }

    free(h->v);
    free(h);
}


// --------------------------------------------
// Programa principal
// --------------------------------------------
int main() {
    int N, M;

    while (scanf("%d %d", &N, &M), N != 0) {

        // limpa estruturas
        for (int i = 1; i <= N; i++) {
            grafo[i] = NULL;
            for (int j = 1; j <= N; j++)
                temAresta[i][j] = 0;
        }

        // primeira leitura: registrar arestas
        int X[M], Y[M], H[M];

        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &X[i], &Y[i], &H[i]);
            temAresta[X[i]][Y[i]] = 1;
        }

        // segunda etapa: montar grafo corretamente
        for (int i = 0; i < M; i++) {
            int a = X[i], b = Y[i], h = H[i];

            if (temAresta[b][a]) {
                // ligação instantânea (recíproca)
                adicionar_aresta(a, b, 0);
            } else {
                adicionar_aresta(a, b, h);
            }
        }

        int K;
        scanf("%d", &K);

        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);

            dijkstra(O);

            if (dist[D] == INT_MAX)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dist[D]);
        }

        printf("\n");
    }

    return 0;
}
