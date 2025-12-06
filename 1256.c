// Tabelas Hash

#include <stdio.h>

int main() {
    int testes;
    scanf("%d", &testes);

    while (testes--) {
        int M, C;
        scanf("%d %d", &M, &C);

        int tabela[M][C];   // guarda os valores encadeados
        int tam[M];         // tamanho atual de cada lista

        // inicializa as listas vazias
        for (int i = 0; i < M; i++) {
            tam[i] = 0;
        }

        // leitura e inserção das chaves
        for (int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);

            int pos = chave % M;  // função de dispersão

            tabela[pos][tam[pos]] = chave;
            tam[pos]++;
        }

        // impressão da tabela
        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            for (int j = 0; j < tam[i]; j++) {
                printf("%d -> ", tabela[i][j]);
            }
            printf("\\\n");
        }

        if (testes) printf("\n"); // linha em branco entre casos
    }

    return 0;
}
