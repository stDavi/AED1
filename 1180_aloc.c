#include<stdio.h>
#include<stdlib.h>  

int main()
{
    int N, i, *x, menor, posicao;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &N);

    int vetor[N];

    x = (int *) malloc(N * sizeof(int));

    if(x){
        printf("Erro: nao foi possivel alocar memoria\n");
        return 1;
    }

    for(i = 0; i < N; i++){
       printf("Digite o valor de vetor[%d]: ", i);
       scanf("%%d", &vetor[i]);

    }

    menor = vetor[0];
    posicao = 0;    

    for (i = 1; i < N; i++){
        if(menor > vetor[i]){
            menor = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\tPosicao do menor valor: %d\n", menor, posicao);

    free(x);

    return 0;
}