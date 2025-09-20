#include <stdio.h>
#include <stdlib.h> // malloc e free

int main() {
    int n;
    int i, j, k, instancia;
    int num, inicioLinha, inicioCol;
    int valido;
    int *contador;

    scanf("%d", &n);

    for (instancia = 1; instancia <= n; instancia++) {
        // Aloca a matriz 9x9
        int **sudoku = (int**) malloc(9 * sizeof(int*));
        for (i = 0; i < 9; i++)
            sudoku[i] = (int*) malloc(9 * sizeof(int));

        // Lê a matriz
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
                scanf("%d", &sudoku[i][j]);

        // Aloca contador (10 posições)
        contador = (int*) malloc(10 * sizeof(int));

        valido = 1;

        // Checa linhas
        for (i = 0; i < 9 && valido; i++) {
            for (k = 1; k <= 9; k++) contador[k] = 0;
            for (j = 0; j < 9; j++) {
                num = sudoku[i][j];
                if (num < 1 || num > 9 || contador[num]) {
                    valido = 0;
                    break;
                }
                contador[num] = 1;
            }
        }

        // Checa colunas
        for (j = 0; j < 9 && valido; j++) {
            for (k = 1; k <= 9; k++) contador[k] = 0;
            for (i = 0; i < 9; i++) {
                num = sudoku[i][j];
                if (num < 1 || num > 9 || contador[num]) {
                    valido = 0;
                    break;
                }
                contador[num] = 1;
            }
        }

        // Checa blocos 3x3
        for (inicioLinha = 0; inicioLinha < 9 && valido; inicioLinha += 3) {
            for (inicioCol = 0; inicioCol < 9 && valido; inicioCol += 3) {
                for (k = 1; k <= 9; k++) contador[k] = 0;
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        num = sudoku[inicioLinha + i][inicioCol + j];
                        if (num < 1 || num > 9 || contador[num]) {
                            valido = 0;
                            break;
                        }
                        contador[num] = 1;
                    }
                    if (!valido) 
                        break;
                }
            }
        }

        // Imprime resultado
        printf("Instancia %d\n", instancia);
        if (valido) 
            printf("SIM\n\n");
        else 
            printf("NAO\n\n");

        free(contador);

        for (i = 0; i < 9; i++)
            free(sudoku[i]);
        free(sudoku);
    }

    return 0;
}
