#include <stdio.h>

int main() {
    int N, i, posicaoMenor;
    
    scanf("%d", &N);
    
    int X[N]; 
    

    for (i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    
    
    int menor = X[0];
    posicaoMenor = 0;
    
    for (i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];
            posicaoMenor = i;
        }
    }
    
    printf("\nMenor valor: %d\n", menor);
    printf("Posicao: %d\n", posicaoMenor);
    
    return 0;
}
