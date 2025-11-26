#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[200001], rankUF[200001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (rankUF[a] < rankUF[b])
        parent[a] = b;
    else if (rankUF[b] < rankUF[a])
        parent[b] = a;
    else {
        parent[b] = a;
        rankUF[a]++;
    }
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int n, m;

    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        Edge *edges = (Edge*)malloc(m * sizeof(Edge));

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rankUF[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        qsort(edges, m, sizeof(Edge), cmp);

        long long cost = 0;
        int used = 0;

        for (int i = 0; i < m && used < n - 1; i++) {
            if (find(edges[i].u) != find(edges[i].v)) {
                unite(edges[i].u, edges[i].v);
                cost += edges[i].w;
                used++;
            }
        }

        printf("%lld\n", cost);

        free(edges);
    }

    return 0;
}
