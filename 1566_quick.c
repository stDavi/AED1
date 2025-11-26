#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = arr[pivotIndex];

    swap(&arr[pivotIndex], &arr[right]); // Move o pivô para o fim

    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

int main() {
    srand(time(NULL)); // evita pior caso repetido

    int NC, N;
    scanf("%d", &NC);

    while (NC--) {
        scanf("%d", &N);

        int *alturas = (int*) malloc(N * sizeof(int));

        for (int i = 0; i < N; i++)
            scanf("%d", &alturas[i]);

        quickSort(alturas, 0, N - 1);

        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}
