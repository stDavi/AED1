#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, N, x[N];  
    int menor = 99999;
    int posicaoMenor = 0;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &N);

    for(i=0; i<N; i++){
        printf("Digite o valor de x[%d]: ", i);
        scanf("%d", &x[i]);
    }
 
    for (i = 0; i < N; i++) {
        if (x[i] < menor) {
            menor = x[i];
            posicaoMenor = i;
        }
    }
    
    printf("\nMenor valor: %d\n", menor);
    printf("Posicao: %d\n", posicaoMenor);
    

    return 0;
}