#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int x[N]; 
    int *ptr = x; 

    for (int i = 0; i < N; i++) {
        scanf("%d", ptr + i); 
    }

    int menor = *ptr;  
    int posicaoMenor = 0;

    for (int i = 1; i < N; i++) {
        if (*(ptr + i) < menor) {
            menor = *(ptr + i);
            posicaoMenor = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicaoMenor);

    return 0;
}
