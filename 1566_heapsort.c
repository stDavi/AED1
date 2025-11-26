#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int maior = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[maior])
        maior = left;

    if (right < n && arr[right] > arr[maior])
        maior = right;

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    // Construir heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrair elementos um por um
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int NC, N;
    scanf("%d", &NC);

    while (NC--) {
        scanf("%d", &N);

        int *alturas = (int*) malloc(N * sizeof(int));

        for (int i = 0; i < N; i++)
            scanf("%d", &alturas[i]);

        heapSort(alturas, N);

        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}
