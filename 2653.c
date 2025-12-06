#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//2653 - Dijkstra - Contagem de Joias

#define MAX 1000001

char *joias[200000];  // como cada joia pode ter tamanho variável, usamos ponteiros
int total = 0;

// comparação para qsort
int cmp(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    char buffer[MAX];

    while (scanf("%s", buffer) != EOF) {
        int len = strlen(buffer);
        joias[total] = (char*) malloc(len + 1);
        strcpy(joias[total], buffer);
        total++;
    }

    if (total == 0) {
        printf("0\n");
        return 0;
    }

    qsort(joias, total, sizeof(char*), cmp);

    int distintos = 1;
    for (int i = 1; i < total; i++) {
        if (strcmp(joias[i], joias[i-1]) != 0)
            distintos++;
    }

    printf("%d\n", distintos);

    return 0;
}
