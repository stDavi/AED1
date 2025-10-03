#include <stdio.h>
#include <string.h>

int main() {
    int N;
    
    scanf("%d\n", &N);

    while (N--) {
        char linha[1001];

        scanf("%s", linha); // lê a string

        int i, abertura = 0, diamantes = 0;

        for (i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '<') {
                abertura++; // guarda um possível início de diamante
            } else 
                if (linha[i] == '>' && abertura > 0) {
                     abertura--;   // fecha o diamante
                     diamantes++;  // formou um diamante
            }
            // se for '.', simplesmente ignora
        }

        //Diamantes formados:
        printf("%d\n", diamantes);
    }

    return 0;
}
