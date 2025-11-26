#include <stdio.h>

void selectionSort(int v[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min])
                min = j;
        }

        if (min != i) {
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

int main() {
    int NC, N;
    scanf("%d", &NC);

    while (NC--) {
        scanf("%d", &N);

        int alturas[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &alturas[i]);
        }

        selectionSort(alturas, N);

        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");
    }

    return 0;
}
