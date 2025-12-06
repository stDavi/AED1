//Estradas Escuras

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
    int custo;
} Estrada;

int pai[200005], tam[200005];
Estrada lista[200005];

/* Função para comparar custos das estradas */
int ordena(const void *x, const void *y) {
    Estrada *e1 = (Estrada*)x;
    Estrada *e2 = (Estrada*)y;
    return e1->custo - e2->custo;
}

/* União–Busca: encontra representante */
int encontra_pai(int x) {
    if (pai[x] == x) return x;
    return pai[x] = encontra_pai(pai[x]);
}

/* Junta dois conjuntos */
void une(int x, int y) {
    x = encontra_pai(x);
    y = encontra_pai(y);
    if (x == y) return;
    if (tam[x] < tam[y]) pai[x] = y;
    else if (tam[y] < tam[x]) pai[y] = x;
    else { pai[y] = x; tam[x]++; }
}

int main() {
    int m, n;

    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;

        long long soma_total = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &lista[i].a, &lista[i].b, &lista[i].custo);
            soma_total += lista[i].custo;
        }

        /* Inicializa Union-Find */
        for (int i = 0; i < m; i++) {
            pai[i] = i;
            tam[i] = 0;
        }

        /* Ordena todas as estradas pelo custo */
        qsort(lista, n, sizeof(Estrada), ordena);

        long long soma_mst = 0;

        /* Executa Kruskal */
        for (int i = 0; i < n; i++) {
            int u = lista[i].a;
            int v = lista[i].b;
            int c = lista[i].custo;

            if (encontra_pai(u) != encontra_pai(v)) {
                une(u, v);
                soma_mst += c;
            }
        }

        /* Economia = total - MST */
        printf("%lld\n", soma_total - soma_mst);
    }

    return 0;
}
