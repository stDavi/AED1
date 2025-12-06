//Mania de Par

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct Aresta {
    int destino, custo;
    struct Aresta *prox;
} Aresta;

Aresta *grafo[10005];
int dist[10005][2];
int visitado[10005][2];

typedef struct {
    int cidade, paridade, custo;
} Estado;

typedef struct {
    Estado dados[200000];
    int tam;
} Heap;

void adicionar_aresta(int u, int v, int g) {
    Aresta *a = (Aresta*)malloc(sizeof(Aresta));
    a->destino = v;
    a->custo = g;
    a->prox = grafo[u];
    grafo[u] = a;
}

void swap(Estado *a, Estado *b) {
    Estado tmp = *a;
    *a = *b;
    *b = tmp;
}

void heap_push(Heap *h, Estado e) {
    int i = h->tam++;
    h->dados[i] = e;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->dados[p].custo <= h->dados[i].custo) break;
        swap(&h->dados[p], &h->dados[i]);
        i = p;
    }
}

Estado heap_pop(Heap *h) {
    Estado ret = h->dados[0];
    h->dados[0] = h->dados[--h->tam];
    int i = 0;

    while (1) {
        int esq = 2*i + 1;
        int dir = 2*i + 2;
        int menor = i;

        if (esq < h->tam && h->dados[esq].custo < h->dados[menor].custo) menor = esq;
        if (dir < h->tam && h->dados[dir].custo < h->dados[menor].custo) menor = dir;

        if (menor == i) break;

        swap(&h->dados[i], &h->dados[menor]);
        i = menor;
    }
    return ret;
}

int main() {
    int C, V;

    while (scanf("%d %d", &C, &V) != EOF) {

        if (C == 0 && V == 0) break;

        for (int i = 1; i <= C; i++) {
            grafo[i] = NULL;
            dist[i][0] = dist[i][1] = INF;
            visitado[i][0] = visitado[i][1] = 0;
        }

        for (int i = 0; i < V; i++) {
            int c1, c2, g;
            scanf("%d %d %d", &c1, &c2, &g);
            adicionar_aresta(c1, c2, g);
            adicionar_aresta(c2, c1, g);
        }

        Heap h;
        h.tam = 0;

        dist[1][0] = 0;
        heap_push(&h, (Estado){1, 0, 0});

        while (h.tam > 0) {
            Estado e = heap_pop(&h);

            int c = e.cidade;
            int p = e.paridade;

            if (visitado[c][p]) continue;
            visitado[c][p] = 1;

            Aresta *at = grafo[c];
            while (at != NULL) {
                int prox = at->destino;
                int custo = at->custo;
                int nova_par = p ^ 1;
                int novo_custo = dist[c][p] + custo;

                if (novo_custo < dist[prox][nova_par]) {
                    dist[prox][nova_par] = novo_custo;
                    heap_push(&h, (Estado){prox, nova_par, novo_custo});
                }

                at = at->prox;
            }
        }

        if (dist[C][0] == INF)
            printf("-1\n");
        else
            printf("%d\n", dist[C][0]);
    }

    return 0;
}
